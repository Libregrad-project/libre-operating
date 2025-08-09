#include <limine.h>

// This defines limine_base_revision symbol in the ".limine_requests" section.
// Note: NO 'static' here, and add the attribute to the macro expansion line.
__attribute__((used, section(".limine_requests")))
volatile LIMINE_BASE_REVISION(3);

// Framebuffer request struct.
__attribute__((used, section(".limine_requests")))
volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

__attribute__((used, section(".limine_requests_start")))
volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
volatile LIMINE_REQUESTS_END_MARKER;
