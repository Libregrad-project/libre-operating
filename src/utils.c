static void hcf(void) {
    for (;;) {
        asm ("hlt");
    }
}

// Make hcf visible to other files if needed
void halt_and_catch_fire(void) {
    hcf();
}
