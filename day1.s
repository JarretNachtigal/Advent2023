	.file	"day1.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"day1.txt"
.LC2:
	.string	"file machine broke"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	-98304(%rsp), %r11
.LPSRL0:
	subq	$4096, %rsp
	orq	$0, (%rsp)
	cmpq	%r11, %rsp
	jne	.LPSRL0
	subq	$1728, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -100024(%rbp)
	cmpq	$0, -100024(%rbp)
	jne	.L2
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %eax
	jmp	.L7
.L2:
	movl	$0, -100028(%rbp)
	jmp	.L4
.L6:
	leaq	-100016(%rbp), %rcx
	movl	-100028(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rax, %rcx
	movq	-100024(%rbp), %rax
	movq	%rax, %rdx
	movl	$100, %esi
	movq	%rcx, %rdi
	call	fgets@PLT
	testq	%rax, %rax
	je	.L4
	addl	$1, -100028(%rbp)
.L4:
	movq	-100024(%rbp), %rax
	movq	%rax, %rdi
	call	feof@PLT
	testl	%eax, %eax
	jne	.L5
	movq	-100024(%rbp), %rax
	movq	%rax, %rdi
	call	ferror@PLT
	testl	%eax, %eax
	je	.L6
.L5:
	movq	-100024(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
.L7:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
