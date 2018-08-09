	.section __TEXT,__text_startup,regular,pure_instructions
	.globl _main
_main:
LFB0:
	movq	_a@GOTPCREL(%rip), %rsi
	movq	_w@GOTPCREL(%rip), %rcx
	leaq	131072(%rcx), %rdi
	jmp	L2
L3:
	movsd	(%rcx,%rax,8), %xmm0
	movq	_v@GOTPCREL(%rip), %rdx
	mulsd	(%rdx,%rax,8), %xmm0
	addq	$1, %rax
	cmpq	$128, %rax
	jne	L3
	movsd	%xmm0, (%rsi)
	addq	$8, %rsi
	addq	$1024, %rcx
	cmpq	%rdi, %rcx
	je	L4
L2:
	movl	$0, %eax
	jmp	L3
L4:
	movl	$0, %eax
	ret
LFE0:
	.comm	_v,1024,5
	.comm	_w,131072,5
	.comm	_a,1024,5
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.byte	0
	.align 3
LEFDE1:
	.subsections_via_symbols
