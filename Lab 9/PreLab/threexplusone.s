	;; Jessica Saviano, Jrs5xrw

	global threexplusone
	section .text


	;; takes in one positive integer, rdi
threexplusone:
	
	mov rax, rdi
	xor r10, r10

base:
	cmp rax, 1		;if one, then done
	je done			;set return to one
	inc r10

	

test:
	test rax, 1
	jnz odd
	jz even


odd:
	lea rax, [rax*3+1]
	jmp base
even:
	shr rax, 1
	jmp base


done:
	mov rax, r10
	ret


	
	
	
				

				
	
	




