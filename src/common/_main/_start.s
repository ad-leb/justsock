.global		_start


.text
_start:
	movq	(%rsp), %rdi			# argc
	leaq	8(%rsp), %rsi                   # argv
	leaq	16(%rsp, %rdi, 8), %rdx        	# env

	xorq	%rbp, %rbp
	xorq	%rax, %rax
	call	main

	movq	%rax, %rdi
	movq	$0x3c, %rax
	syscall
