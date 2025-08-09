#include <limine.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limine_requests.h>
extern volatile struct limine_framebuffer_request framebuffer_request;



void halt_and_catch_fire(void);

void kmain(void) {
    if (!LIMINE_BASE_REVISION_SUPPORTED) {
        halt_and_catch_fire();
    }

    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        halt_and_catch_fire();
    }

    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    for (size_t i = 0; i < 100; i++) {
        volatile uint32_t *fb_ptr = framebuffer->address;
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
    }

    halt_and_catch_fire();
}
