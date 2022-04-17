[bits 64]

SEGMENT .text
global getPort, setPort

getPort:
	push rdx
	push rax

	mov rdx, rdi
	in al, dx

	pop rax
	pop rdx
	ret

setPort:
	push rdx
	push rax

	mov rdx, rdi
	mov rax, rsi
	out dx, al

	pop rax
	pop rdx
	ret
