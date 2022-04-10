[BITS 64]

SEGMENT .text
extern Main

Entry:
	mov ax, 0x08
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ss, ax
	mov rsp, 0x8FFFFE
	mov rbp, 0x8FFFFE

	call Main
