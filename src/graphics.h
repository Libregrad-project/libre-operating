#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <stddef.h>


void draw_char(volatile uint32_t *framebuffer, size_t pitch, int x, int y, char c, uint32_t color);
void draw_string(volatile uint32_t *framebuffer, size_t pitch, int x, int y, const char *str, uint32_t color);

#endif // GRAPHICS_H
