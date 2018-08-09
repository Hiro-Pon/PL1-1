	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_func                   ## -- Begin function func
	.p2align	4, 0x90
_func:                                  ## @func
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	mov	eax, r8d
	shr	eax, 31
	add	eax, r8d
	sar	eax
	cmp	eax, ecx
	jle	LBB0_5
## BB#1:
	movsxd	r8, eax
	movsxd	rcx, ecx
	lea	r9, [rcx + 4*rcx]
	shl	r9, 14
	add	r9, rsi
	mov	eax, 10240
	sub	rax, rcx
	lea	r10, [rax + 4*rax]
	shl	r10, 14
	add	r10, rsi
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	mov	esi, 10240
	sub	rsi, rcx
	xor	eax, eax
	.p2align	4, 0x90
LBB0_3:                                 ##   Parent Loop BB0_2 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movsd	xmm0, qword ptr [r9 + 8*rax] ## xmm0 = mem[0],zero
	mulsd	xmm0, qword ptr [rdx + 8*rax]
	addsd	xmm0, qword ptr [rdi + 8*rcx]
	movsd	qword ptr [rdi + 8*rcx], xmm0
	movsd	xmm0, qword ptr [r10 + 8*rax] ## xmm0 = mem[0],zero
	mulsd	xmm0, qword ptr [rdx + 8*rax]
	addsd	xmm0, qword ptr [rdi + 8*rsi]
	movsd	qword ptr [rdi + 8*rsi], xmm0
	inc	rax
	cmp	rax, 10240
	jne	LBB0_3
## BB#4:                                ##   in Loop: Header=BB0_2 Depth=1
	inc	rcx
	add	r9, 81920
	add	r10, -81920
	cmp	rcx, r8
	jne	LBB0_2
LBB0_5:
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi5:
	.cfi_def_cfa_register rbp
	push	rbx
	push	rax
Lcfi6:
	.cfi_offset rbx, -24
	mov	edi, 839024640
	call	_malloc
	mov	rbx, rax
	lea	rsi, [rbx + 81920]
	lea	rdx, [rbx + 838942720]
	xor	ecx, ecx
	mov	r8d, 10240
	mov	rdi, rbx
	call	_func
	movsd	xmm0, qword ptr [rbx + 40960] ## xmm0 = mem[0],zero
	lea	rdi, [rip + L_.str]
	mov	al, 1
	call	_printf
	xor	eax, eax
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"a %f\n"


.subsections_via_symbols
