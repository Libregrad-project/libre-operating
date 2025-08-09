#include "graphics.h"
#include "font8x8.h"
#include <stddef.h>
#include <stdint.h>

void draw_char(volatile uint32_t *fb, size_t pitch, int x, int y, char c, uint32_t color) {
    if ((unsigned char)c > 127) return;  // guard for font range
    const uint8_t *glyph = font8x8_basic[(unsigned char)c];
    for (int row = 0; row < 8; row++) {
        uint8_t bits = glyph[row];
        for (int col = 0; col < 8; col++) {
            // Use MSB on left, so check bit 7-col
            if (bits & (1 << (7 - col))) {
                fb[(y + row) * (pitch / 4) + (x + col)] = color;
            }
        }
    }
}

void draw_string(volatile uint32_t *fb, size_t pitch, int x, int y, const char *str, uint32_t color) {
    int cursor_x = x;
    while (*str) {
        draw_char(fb, pitch, cursor_x, y, *str++, color);
        cursor_x += 8;
    }
}
