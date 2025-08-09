; kernel.asm - simple protected mode kernel in assembly
; Assemble with: nasm -f elf32 kernel.asm -o kernel.o

[bits 32]

section .multiboot
    align 4
    dd 0x1BADB002          ; magic number
    dd 0x00                ; flags (no framebuffer)
    dd -(0x1BADB002 + 0x00); checksum

section .text
global _start
_start:
    ; Clear screen (simple, just overwrite VGA text buffer)
    mov edi, 0xb8000       ; VGA text mode buffer
    mov ecx, 80*25         ; 80x25 screen
    mov eax, 0x07200720    ; ' ' with attribute 0x07 (gray on black), 2 chars per dword

clear_loop:
    mov [edi], eax
    add edi, 4
    loop clear_loop

    ; Print a message (simple, direct to VGA)
    mov esi, message
    mov edi, 0xb8000       ; start of VGA buffer
print_loop:
    lodsb                  ; load byte from [esi] to al, increment esi
    cmp al, 0
    je done_print
    mov ah, 0x07           ; attribute byte (gray on black)
    mov [edi], ax          ; write character + attribute
    add edi, 2
    jmp print_loop

done_print:
    ; Halt CPU (infinite loop)
halt:
    hlt
    jmp halt

section .data
message db 'Hello from pure ASM kernel!',0
