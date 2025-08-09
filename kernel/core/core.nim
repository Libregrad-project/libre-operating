proc kernel_main() {.importc: "kernel_main", cdecl, header: "<boot.h>".}

proc initKernel() =
    echo "Kernel Initialized in Nim."
    kernel_main()

initKernel()
