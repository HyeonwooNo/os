#include "Page.h"
#include "Print.h"

void InitializePageTable(void) {
   InitializePML4Table();
   InitializePageDirectoryPointerTable();
   InitilizePageTable();
}

void InitializePML4Table(void) {
	Pml4Entry * pml4Entry = (Pml4Entry *)PML4_BASE_ADDRESS;
	pml4Entry->lower4Byte = PAGE_LOWER4B_FLAGS_P | PAGE_LOWER4B_FLAGS_RW \
							| PDPTABLE_BASE_ADDRESS;
	pml4Entry->upper4Byte = (PDPTABLE_BASE_ADDRESS >> 28) & 0xFF;
	for(int i=1; i<TABLE_COUNT; i++) {
		pml4Entry[i].lower4Byte = 0x0;
		pml4Entry[i].upper4Byte = 0x0;
	}
}

void InitializePageDirectoryPointerTable(void) { //´ÜÀ§ : gb
	PdpEntry * pdpEntry = (PdpEntry *)PDPTABLE_BASE_ADDRESS;
	for(int i=0; i<MAX_MEMORY_SIZE; i++) {
		int pageTableAddress = PAGETABLE_BASE_ADDRESS + (i*PAGE_TABLE_SIZE);
		pdpEntry[i].lower4Byte = PAGE_LOWER4B_FLAGS_P | PAGE_LOWER4B_FLAGS_RW \
							| pageTableAddress;
		pdpEntry[i].upper4Byte = (pageTableAddress >> 28) & 0xFF;
	}
	for(int i=MAX_MEMORY_SIZE; i<TABLE_COUNT; i++) {
		pdpEntry[i].lower4Byte = 0x0;
		pdpEntry[i].upper4Byte = 0x0;
	}
}

void InitilizePageTable(void) {
	PdEntry * pdEntry = (PdEntry *)PAGETABLE_BASE_ADDRESS;
	for(int i=0; i < TABLE_COUNT*MAX_MEMORY_SIZE; i++) {
		int physicalAddress = i*0x200000;
		pdEntry[i].lower4Byte = PAGE_LOWER4B_FLAGS_P | PAGE_LOWER4B_FLAGS_RW \
				| (PDIRECTORY_LOWER4B_FLAGS_PS | physicalAddress);
		pdEntry[i].upper4Byte = (physicalAddress >> 32) & 0xFF;
	}
}
