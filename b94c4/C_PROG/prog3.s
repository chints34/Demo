	.file	"prog3.c"
	.section	.rodata
.LC0:
	.string	"enter a and b and c"
.LC1:
	.string	"%d%d%d"
.LC2:
	.string	"a is smaller"
.LC3:
	.string	"b is smaller"
.LC4:
	.string	"c is smaller"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$.LC0, (%esp)
	call	printf
	movl	$c, 12(%esp)
	movl	$b, 8(%esp)
	movl	$a, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	a, %edx
	movl	b, %eax
	cmpl	%eax, %edx
	jge	.L2
	movl	a, %edx
	movl	c, %eax
	cmpl	%eax, %edx
	jge	.L2
	movl	$.LC2, (%esp)
	call	printf
.L2:
	movl	b, %edx
	movl	a, %eax
	cmpl	%eax, %edx
	jge	.L5
	movl	b, %edx
	movl	c, %eax
	cmpl	%eax, %edx
	jge	.L5
	movl	$.LC3, (%esp)
	call	printf
	jmp	.L10
.L5:
	movl	$.LC4, (%esp)
	call	printf
.L10:
	addl	$20, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.comm	a,4,4
	.comm	b,4,4
	.comm	c,4,4
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
