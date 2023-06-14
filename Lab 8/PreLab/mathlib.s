	;Jessica Saviano, Jrs5xrw, inspo from vecsum.s
	global product 		;global var for product subroutine
	global power 		;global var for power subroutine

	section .text
product:
	xor rax, rax 		
	xor r10, r10 		;zero out count
start:
	cmp r10,rsi 		;test to see if loop is done
	je  done		;jump to done, youve finished the loop
	add rax,rdi		;actual math done here
	inc r10			; increase your count
	jmp start 		;loop back to start
done:
	ret 			;you're done w product!
power:
	cmp rsi, 0 		;base case for recursion: if expo=0 return 1
	mov rax, 1 		;make return 1 if base case is true
	je done1		; go to return if base case is true
recursion:
	dec rsi 		;decrement exponent
	call power 		;recursion
  	mov rsi,rax		;make return type the one it needs to be (rax)
	call product			;multiply recursion power(x, y-1)*x
done1:
	ret 			;you're done w power!


	
	
	

	

	
	
	
