	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
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
	mov	dword ptr [rbp - 4], 0
	mov	qword ptr [rbp - 16], 0
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	cmp	qword ptr [rbp - 16], 128
	jge	LBB0_8
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	qword ptr [rbp - 24], 0
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmp	qword ptr [rbp - 24], 128
	jge	LBB0_6
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=2
	mov	rax, qword ptr [rip + _a@GOTPCREL]
	mov	rcx, qword ptr [rip + _v@GOTPCREL]
	mov	rdx, qword ptr [rip + _w@GOTPCREL]
	mov	rsi, qword ptr [rbp - 16]
	shl	rsi, 10
	add	rdx, rsi
	mov	rsi, qword ptr [rbp - 24]
	movsd	xmm0, qword ptr [rdx + 8*rsi] ## xmm0 = mem[0],zero
	mov	rdx, qword ptr [rbp - 24]
	mulsd	xmm0, qword ptr [rcx + 8*rdx]
	mov	rcx, qword ptr [rbp - 16]
	movsd	qword ptr [rax + 8*rcx], xmm0
## BB#5:                                ##   in Loop: Header=BB0_3 Depth=2
	mov	rax, qword ptr [rbp - 24]
	add	rax, 1
	mov	qword ptr [rbp - 24], rax
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	add	rax, 1
	mov	qword ptr [rbp - 16], rax
	jmp	LBB0_1
LBB0_8:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.comm	_w,131072,4             ## @w
	.comm	_v,1024,4               ## @v
	.comm	_a,1024,4               ## @a

.subsections_via_symbols
