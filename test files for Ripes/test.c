/*

*** test.c ***

*** It can be simulated with Ripes. To inspect data memory in Ripes set RAM address to 0x00001000 ***

You need to make an ELF file without headers, which starts at the address 0x00000000, with the following command:

riscv-none-elf-gcc -march=rv32im -mabi=ilp32 -nostdlib -ffreestanding -Tmemory_map.ld -o test.elf test.c

As we are using a bare metal system without an elf loader, we get rid of the elf part and use the binary only:

riscv-none-elf-objcopy -O binary test.elf test.bin


It can be simulated with Ripes under Windows. 

In Ripes you can load and run ELF or BIN files.

Run the program and, to access the 5 data addresses where the program is writing, set starting memory in Ripes at address 0x00001000.


*/

#include <stdint.h>

// RAM data segment address set at the beginning of the second Kbyte. 
// The first Kbyte contains the program.
#define START_DATA_ADDRESS 0x00001000

int main(void) 
{
	volatile uint32_t *a = (uint32_t*)(START_DATA_ADDRESS);
	volatile uint32_t *b = (uint32_t*)(START_DATA_ADDRESS + 0x4);
	volatile uint32_t *c = (uint32_t*)(START_DATA_ADDRESS + 0x8);
	volatile uint32_t *d = (uint32_t*)(START_DATA_ADDRESS + 0xC);
	volatile uint32_t *e = (uint32_t*)(START_DATA_ADDRESS + 0x10);
	
	volatile uint32_t x = 0;
	
	*a = 0xFF; 
	*b = 0xFFFF; 
	*c = 0xFFFFFF; 
	*d = 0xFFFFFFFF; 

	while (1) {
		*e = x;
		x++;
		if (x == 0xFFFFFFFF) x = 0;
	}
}