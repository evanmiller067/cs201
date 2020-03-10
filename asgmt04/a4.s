	.file	"a4.c"
	.section	.rodata
.LC1:
	.string	"CS201 - Asgmt 4 - Evan Miller"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$8, %esi
	movl	$10000, %edi
	call	calloc
	movq	%rax, -48(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -40(%rbp)
	movl	$.LC1, %edi
	call	puts
	movl	$0, -12(%rbp)
	jmp	.L2
.L5:
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -40(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L3
.L4:
	movq	-24(%rbp), %rax
	movsd	(%rax), %xmm1
	movq	-24(%rbp), %rax
	addq	$8, %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$16, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$24, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$32, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$40, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-32(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$48, %rax
	movsd	(%rax), %xmm1
	movq	-24(%rbp), %rax
	addq	$56, %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$64, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$72, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$80, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movq	-24(%rbp), %rax
	addq	$88, %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-40(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	addq	$96, -24(%rbp)
.L3:
	movq	-48(%rbp), %rax
	addq	$80000, %rax
	cmpq	%rax, -24(%rbp)
	jb	.L4
	movsd	-32(%rbp), %xmm0
	addsd	-40(%rbp), %xmm0
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	addl	$1, -12(%rbp)
.L2:
	cmpl	$599999, -12(%rbp)
	jle	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
