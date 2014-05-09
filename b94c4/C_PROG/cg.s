	.file	"cg.c"
	.section	.rodata
.LC0:
	.string	"hello"
.LC1:
	.string	"how r u"
	.text
.globl vector
	.type	vector, @function
vector:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$.LC0, (%esp)
	call	puts
	call	f1
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, (%esp)
	call	exit
	.size	vector, .-vector
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
