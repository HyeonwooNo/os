#include "Print.h"

static int currentPoint=0xB8460;
static int alphabetDigit[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char * okSign = "OK";
char * failSign = "Fail";

void moveToNextLine(void) {
	int xIdx = (currentPoint-VIDEO_MEMORY_ADDR) % ONE_LINE_SIZE;
	currentPoint+=(ONE_LINE_SIZE-xIdx);
}

void viewCharacter(BYTE ch) {
	VideoCharacter * videoMemory = (VideoCharacter *)currentPoint;
	videoMemory->character = ch;
	currentPoint+=ONE_CHAR_SIZE;
}

void printString(const char* str) {
	for(int i=0; str[i]!=NULL; i++) {
		if(str[i]=='\n')
			moveToNextLine();
		else
			viewCharacter(str[i]);
	}
}

void puts(const char* str) {
	printString(str);
	moveToNextLine();
}

void printInt(int num, int radix) {
	char charNum[32] = {0};
	int convertConstant = '1'-1;
	int count = 0;
	if(num==0) {
		viewCharacter('0');
		return;
	}
	for(int i=0; i<32; i++)
		charNum[i]=-1;
	while(num>0) {
		int digit = num%radix;
		if(digit<10)
			charNum[count] = digit+convertConstant;
		else
			charNum[count] = alphabetDigit[digit%10];
		num /= radix;
		count++;
	}
	reverseArray(charNum, count);
	for(int i=0; i<32; i++) {
		if(charNum[i]!=-1)
			viewCharacter(charNum[i]);
		else
			break;
	}
}

int printStateAndReturn(bool state) {
	if(state==TRUE)
		puts(okSign);
	else
		puts(failSign);
	return state;
}
