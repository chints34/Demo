	.file	"cub.c"
	.section	.rodata
.LC0:
	.string	"welcome to hyb"
	.text
.globl vector
	.type	vector, @function
vector:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, (%esp)
	call	exit
	.size	vector, .-vector
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
