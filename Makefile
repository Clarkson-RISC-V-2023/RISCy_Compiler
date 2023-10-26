.PHONY: all

C_FILE 			= ./src/test3.c
PP  			= python3 ./PostProcessingTools/gpp
INSTRUCTIONS    = ./PostProcessingTools/instruction_lib.txt
MEM_INIT		= mem_init
OUT_DIR 		= ./out
OUT_FILE_NAME 	= RISCy
COMPILE_FLAGS	= -march=rv32imf -mabi=ilp32

all: mem_init

cobject:
	riscv32-unknown-linux-gnu-gcc $(COMPILE_FLAGS) -c $(C_FILE) -o $(OUT_FILE_NAME).o

link: cobject
	riscv32-unknown-linux-gnu-ld $(OUT_FILE_NAME).o -Ttext 0 -o $(OUT_FILE_NAME).bin

showhex: link
	riscv32-unknown-linux-gnu-objdump -D $(OUT_FILE_NAME).bin

mem_init: link
	riscv32-unknown-linux-gnu-objdump -D $(OUT_FILE_NAME).bin > tmp.txt
	$(PP) tmp.txt -o $(MEM_INIT) -i $(INSTRUCTIONS)
	#rm -rf tmp.txt

clean:
	rm -rf *.s *.o *.elf $(OUT_FILE_NAME)*

rclean:
	rm -rf *.s *.o *.elf $(OUT_FILE_NAME)*
	rm -rf $(MEM_INIT)