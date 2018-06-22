section .text

global _tea_encrypt

_tea_encrypt:

	push	rbp
Lcfi0:
Lcfi1:
	mov	rbp, rsp
Lcfi2:
	mov	qword  [rbp - 8], rdi
	mov	qword  [rbp - 16], rsi
	mov	dword  [rbp - 28], 0
	mov	rsi, qword  [rbp - 8]
	mov	eax, dword  [rsi]
	mov	dword  [rbp - 20], eax
	mov	rsi, qword  [rbp - 8]
	mov	eax, dword  [rsi + 4]
	mov	dword  [rbp - 24], eax
	mov	rsi, qword  [rbp - 16]
	mov	eax, dword  [rsi]
	and	eax, 255
	mov	cl, al
	mov	byte  [rbp - 33], cl
	mov	rsi, qword  [rbp - 16]
	mov	eax, dword  [rsi]
	shr	eax, 8
	and	eax, 255
	mov	cl, al
	mov	byte  [rbp - 34], cl
	mov	rsi, qword  [rbp - 16]
	mov	eax, dword  [rsi]
	shr	eax, 16
	and	eax, 255
	mov	cl, al
	mov	byte  [rbp - 35], cl
	mov	rsi, qword  [rbp - 16]
	mov	eax, dword  [rsi]
	shr	eax, 24
	and	eax, 255
	mov	cl, al
	mov	byte  [rbp - 36], cl
	mov	dword  [rbp - 32], 0
LBB0_1:
	mov	eax, dword  [rbp - 32]
	mov	ecx, eax
	add	ecx, 1
	mov	dword  [rbp - 32], ecx
	cmp	eax, 32
	jae	LBB0_3

	mov	eax, dword  [rbp - 28]
	add	eax, -1640531527
	mov	dword  [rbp - 28], eax
	mov	eax, dword  [rbp - 24]
	shl	eax, 4
	movzx	ecx, byte  [rbp - 33]
	add	eax, ecx
	mov	ecx, dword  [rbp - 24]
	add	ecx, dword  [rbp - 28]
	xor	eax, ecx
	mov	ecx, dword  [rbp - 24]
	shr	ecx, 5
	movzx	edx, byte  [rbp - 34]
	add	ecx, edx
	xor	eax, ecx
	add	eax, dword  [rbp - 20]
	mov	dword  [rbp - 20], eax
	mov	eax, dword  [rbp - 20]
	shl	eax, 4
	movzx	ecx, byte  [rbp - 35]
	add	eax, ecx
	mov	ecx, dword  [rbp - 20]
	add	ecx, dword  [rbp - 28]
	xor	eax, ecx
	mov	ecx, dword  [rbp - 20]
	shr	ecx, 5
	movzx	edx, byte  [rbp - 36]
	add	ecx, edx
	xor	eax, ecx
	add	eax, dword  [rbp - 24]
	mov	dword  [rbp - 24], eax
	jmp	LBB0_1
LBB0_3:
	mov	eax, dword  [rbp - 20]
	mov	rcx, qword  [rbp - 8]
	mov	dword  [rcx], eax
	mov	eax, dword  [rbp - 24]
	mov	rcx, qword  [rbp - 8]
	mov	dword  [rcx + 4], eax
	pop	rbp
	ret

