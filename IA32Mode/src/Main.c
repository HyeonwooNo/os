#include "Type.h"
#include "Print.h"
#include "Descriptor.h"
#include "RegControl.h"
#include "Handler.h"

const char * switchToIA32eMode = "Switch to IA-32e mode";
const char * successBooting = "Success Booting";
const char * initDiscriptor = "Initilize Discriptor";
const char * discriptorLoadComplete = "Discriptor Load Complete";
const char * picInitilize = "PIC initilize";
const char * intInitilize = "Interrupt initilize";

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

	puts(picInitilize);
	a/=0;
	while(1);
}
