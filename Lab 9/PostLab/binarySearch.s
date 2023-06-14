	;; Jessica Saviano, jrs5xrw
	global binarySearch
	section .text
	;; rdi = pointer to array
	;; rsi = beg of array (int)
	;; rdx = end of array (int)
	;; rcx = target element, k (int)
	;; rax = index where the element is found, or -1 if wasn't found
	;; r10 = mid 


binarySearch:
	xor r10, r10
	mov rax, -1

loop:	
	cmp rsi,rdx
	jg not
	lea r10,[rsi+rdx]
	shr r10, 1
	cmp [rdi+4*r10],ecx
	jl lesser
	jg bigger
	je equal

	
lesser:
	mov rsi, r10
	inc rsi
	jmp loop
bigger:
	mov rdx, r10
	dec rdx
	jmp loop

equal:
	mov rax, r10
	ret
		
not:

	ret











	
