	;; Jessica Saviano, jrs5xrw

	global linearSearch
	section .text

	;; rdi =pointer to array, rsi = size of array, rdx = target

	;; r10 = i (index a[i])

linearSearch:
	xor r10,r10 		;zero out i, start at beg. of array
	xor rax,rax		;zero out return

start:
	cmp r10,rsi 		;loop condition i< size
	je not			
	cmp edx,[rdi+4*r10]
	je yes
	cmp edx,[rdi+4*r10]
	jne redo


redo:
	inc r10
	jmp start		;reloop through 

yes:
	mov rax,r10		;if found, return correct i
	ret

not:	mov rax, -1			;not found, return -1
	ret
	
