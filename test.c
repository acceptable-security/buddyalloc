#include "buddy.h"

// Stupid & simple tests
int main(int argc, char* argv[]) {
	size_t size = 0x100 + sizeof(buddy_alloc_t);
	uintptr_t address = (uintptr_t) malloc(size);
	buddy_alloc_t* buddy = buddy_init(address, size);
	
	printf("[T] Initialization finished...\n");
	buddy_status(buddy);
	printf("\n");

	printf("[T] Allocating 12 bytes...\n");
	void* test = buddy_alloc(buddy, 12);
	buddy_status(buddy);
	printf("\n");

	printf("[T] Received %08x\n", test);
	buddy_dealloc(buddy, test, 12);
	buddy_status(buddy);
	printf("\n");

	free(address);
}