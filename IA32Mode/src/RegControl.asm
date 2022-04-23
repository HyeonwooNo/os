[bits 64]

SEGMENT .text
global loadGDTR, loadTR, loadIDTR, enableInterrupt, disableInterrupt

loadGDTR:
	lgdt [rdi]
	ret

loadTR:
	ltr di
	ret

loadIDTR:
	lidt [rdi]
	ret

enableInterrupt:
	sti
	ret

disableInterrupt:
	cli
	ret

