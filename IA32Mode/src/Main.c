#include "Type.h"
#include "Print.h"
#include "Descriptor.h"
#include "RegControl.h"
#include "Handler.h"
#include "Memory.h"

const char * switchToIA32eMode = "Switch to IA-32e mode";
const char * successBooting = "Success Booting";
const char * initDiscriptor = "Initilize Discriptor";
const char * discriptorLoadComplete = "Discriptor Load Complete";
const char * picInitilize = "PIC initilize";
const char * intInitilize = "Interrupt Initilize";
const char * memPoolInitlize = "Memory Pool Initilize";

void Main(void) {
	int a=1;
	puts(switchToIA32eMode);
	puts(successBooting);

	initilizeDiscriptor();
	puts(initDiscriptor);

	loadGDTR(GDTR_ADDRESS);
	loadTR(TSS_DESCRIPTOR_OFFSET);
	loadIDTR(IDTR_ADDRESS);
	puts(discriptorLoadComplete);

	initializePIC();
	puts(picInitilize);
	//a/=0;
	initMemoryBitmap();
	puts(memPoolInitlize);
	printMemoryRate();
	while(1);
}
