#ifndef LIMINE_REQUESTS_H
#define LIMINE_REQUESTS_H

#include <limine.h>

// This extern declaration lets other files see the symbol defined in limine_requests.c
extern volatile uint8_t limine_base_revision[3];

// Declare framebuffer request
extern volatile struct limine_framebuffer_request framebuffer_request;

#endif // LIMINE_REQUESTS_H
