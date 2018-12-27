	.file	"temp.c"
	.text
	.comm	temp0,4,4
	.comm	temp1,4,4
	.comm	temp2,4,4
	.comm	temp4,4,4
	.section	.rodata
.str3:
	.string	"%d"
.str5:
	.string	"%d, %d\n"
	.text
	.globl	func
	.type	func, @function
func:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$9, %eax
	addl	$9, %eax
	movl	%eax, temp0(%rip)
	movl	temp0(%rip), %eax
	leave
	ret
	.size	func, .-func
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	$1, temp2(%rip)
	leaq	.str3(%rip), %rdi
	leaq	temp1(%rip), %rax
	movq	%rax, %rsi
	call	__isoc99_scanf@PLT
	jmp	.L0
.L1:
	movl	temp1(%rip), %eax
	imull	temp2(%rip), %eax
	movl	%eax, temp2(%rip)
	movl	temp1(%rip), %eax
	subl	$1, %eax
	movl	%eax, temp1(%rip)
.L0:
	movl	temp1(%rip), %eax
	cmpl	$0, %eax
	setle	%al
	movzbl	%al, %eax
	testl	%eax, %eax
	je	.L1
	call	func
	movl	%eax, temp4(%rip)
	leaq	.str5(%rip), %rdi
	movq	temp2(%rip), %rsi
	movq	temp4(%rip), %rdx
	call	printf@PLT
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"Vampire very-simple-c-compiler"
	.section	.note.GNU-stack,"",@progbits
