.PHONY:

C_FILE 			= ./src/test.c
OUT_DIR 		= ./out
OUT_FILE_NAME 	= RISCy
COMPILE_FLAGS	= -march=rv32i -mabi=ilp32

all: clean assembly cobject linkforELF ELFtoBin BintoHex move

assembly:
	riscv32-unknown-linux-gnu-gcc -S $(COMPILE_FLAGS) -c $(C_FILE) -o $(OUT_FILE_NAME).s

cobject:
	riscv32-unknown-linux-gnu-gcc $(COMPILE_FLAGS) -c $(C_FILE) -o $(OUT_FILE_NAME).o

linkforELF:
	riscv32-unknown-linux-gnu-gcc $(COMPILE_FLAGS) $(OUT_FILE_NAME).o -o $(OUT_FILE_NAME).elf

ELFtoBin:
	riscv32-unknown-linux-gnu-objcopy -O binary $(OUT_FILE_NAME).elf $(OUT_FILE_NAME).bin

BintoHex:
	xxd -p -c 4 $(OUT_FILE_NAME).bin $(OUT_FILE_NAME).hex

BintoMIF:
	python3 bin_to_mif.py $(OUT_FILE_NAME).bin

move:
	mkdir -p $(OUT_DIR)
	mv $(OUT_FILE_NAME)* $(OUT_DIR)
	cp $(C_FILE) $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)
	rm -rf *.s *.o *.elf $(OUT_FILE_NAME)*

	