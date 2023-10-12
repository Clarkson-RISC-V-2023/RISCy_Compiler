# RISCy Compiler and Assembler

Install `hexdump` https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor

## Compile C code to assembly
- use `riscv32-unknown-linux-gnu-gcc -S <your_file.c>`
    - `-S` is Compile only; do not assemble or link.
    - `-c` is Compile and assemble, but do not link.
- Compile only with RV32i
    - add `-march=rv32i`
    - and `-mabi=ilp32` to remove the requirement of double precition floating point
    - `riscv32-unknown-linux-gnu-gcc -S -march=rv32i -mabi=ilp32 <your_file.c>`

## Compile C code to binary
- Just remove the `-S` `riscv32-unknown-linux-gnu-gcc <your_file.c>`
