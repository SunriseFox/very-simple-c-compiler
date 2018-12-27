	.file	"temp.c"
	.text
	.comm	temp0,4,4
	.comm	temp1,4,4
	.comm	temp2,4,4
	.comm	temp6,4,4
	.comm	temp7,4,4
	.section	.rodata
.str4:
	.string	"the result is:"
.str5:
	.string	"%d"
.str8:
	.string	"%s%d, %d\n"
	.text
	.globl	func
	.type	func, @function
func:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$8, temp0(%rip)
	movl	$0, %eax
	test	%eax, %eax
	jne	.L2
	movl	$1, %eax
	test	%eax, %eax
	je	.L3
.L2:
	movl	$1, %eax
	jmp	.L4
.L3:
	movl	$0, %eax
.L4:
	testl	%eax, %eax
	je	.L0
	movl	$1, %eax
	leave
	ret
	jmp	.L1
.L0:
	movl	$2, %eax
	leave
	ret
.L1:
	leave
	ret
	.size	func, .-func
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, temp2(%rip)
	leaq	.str5(%rip), %rdi
	leaq	temp1(%rip), %rax
	movq	%rax, %rsi
	call	__isoc99_scanf@PLT
	movl	$1, temp6(%rip)
	jmp	.L6
.L5:
	movl	temp6(%rip), %eax
	imull	temp2(%rip), %eax
	movl	%eax, temp2(%rip)
	incl	temp6(%rip)
.L6:
	movl	temp6(%rip), %eax
	cmpl	temp1(%rip), %eax
	setg	%al
	movzbl	%al, %eax
	testl	%eax, %eax
	je	.L5
	call	func
	movl	%eax, temp7(%rip)
	leaq	.str8(%rip), %rdi
	leaq	.str4(%rip), %rsi
	movq	temp2(%rip), %rdx
	movq	temp7(%rip), %rcx
	call	printf@PLT
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"Vampire very-simple-c-compiler"
	.section	.note.GNU-stack,"",@progbits
