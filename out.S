	.file	"temp.c"
	.text
	.comm	temp0,4,4
	.comm	temp1,4,4
	.section	.rodata
.str2:
	.string	"%d"
.str3:
	.string	"%d, %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, %eax
	addl	$1, %eax
	addl	$1, %eax
	movl	%eax, temp1(%rip)
	leaq	.str2(%rip), %rdi
	leaq	temp0(%rip), %rax
	movq	%rax, %rsi
	call	__isoc99_scanf@PLT
	leaq	.str3(%rip), %rdi
	movq	temp0(%rip), %rsi
	movq	temp1(%rip), %rdx
	call	printf@PLT
	leave
	ret
