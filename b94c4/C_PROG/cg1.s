	.file	"cg1.c"
	.section	.rodata
.LC0:
	.string	"hello"
.LC1:
	.string	"how r u"
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
	subl	$4, %esp
	movl	$.LC0, (%esp)
	call	puts
	call	f1
	movl	$.LC1, (%esp)
	call	puts
	addl	$4, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
.globl f1
	.type	f1, @function
f1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	f2
	leave
	ret
	.size	f1, .-f1
	.section	.rodata
.LC2:
	.string	"friends"
	.text
.globl f2
	.type	f2, @function
f2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$.LC2, (%esp)
	call	printf
	leave
	ret
	.size	f2, .-f2
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
