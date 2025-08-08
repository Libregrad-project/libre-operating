# TODO: We need to make the kernel system, which can include / import external Assembly (ASM) code, 
# Which then will be used inside the code-base.

# Declare the external kernel_main symbol from the boot.o file. Which we get with:
# nasm -f elf64 -o boot.o boot.asm

#Since kernel_main is an external function declared in the assembly code, 
# we will need to provide a simple C header file (boot.h) that declares this external function.

# Example:
# // boot.h
# void kernel_main(void); 

# And then nim c -d:nodejs --link:boot.o core.nim 

#proc kernel_main() {.importc: "kernel_main", cdecl, header: "<boot.h>".}

proc initKernel() =
    echo "Kernel Initialized."
 #   kernel_main() 

initKernel()