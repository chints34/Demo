	.file	"prog2.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"enter the value of a and b and c"
.LC1:
	.string	"%f%f%f"
.LC3:
	.string	"%f"
	.align 4
.LC2:
	.long	1077936128
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
	flds	a
	flds	b
	faddp	%st, %st(1)
	flds	c
	faddp	%st, %st(1)
	fstps	d
	flds	d
	flds	.LC2
	fdivrp	%st, %st(1)
	fstps	e
	flds	e
	fstpl	4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	addl	$20, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.comm	a,4,4
	.comm	b,4,4
	.comm	c,4,4
	.comm	d,4,4
	.comm	e,4,4
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
