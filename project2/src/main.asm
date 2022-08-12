jmp start
	temp dw 0	; temporary variable helps for taking the input
	myflag db 0	; need to check if whitespace comes after operator
	outp db 4 dup 0	; the output string
	cr dw 10,13,"$"	; carriage return
	counter dw 0
	onenumberflag db 0	; need to check if the input consists of just one number

start:
	mov cx, 0	; cx stores current number being read
	mov myflag, 0	; set flag to 0

getnum:	
	mov ah, 01h
	int 21h		; read char to al
	mov dx, 0
	mov dl, al	; dx stores current char
	mov ax, cx	; ax set to previous digits for the case of a number with multiple digits
	cmp dl, 0D	; check if next char is enter
	je endjump
	cmp dl, ' '	; check if next char is a whitespace
	je wspace
	jmp converttodec

converttodec:
	cmp dx, '@'	; check if current digit is a hex digit
	jg ishex
	jl isdec

isdec:
	cmp dx, '+'
	je addition
	cmp dx, '*'
	je multiplication
	cmp dx, '/'
	je division
	cmp dx, '&'
	je bitwiseand
	mov myflag, 1	; if char is not an operator set flag to 1
	sub dx, '0'	; convert char to hex
	jmp continuetoconvert

ishex:
	cmp dx, '^'
	je bitwisexor
	cmp dx, '|'
	je bitwiseor
	mov myflag, 1	; if char is not an operator set flag to 1
	sub dx, '7'	; convert char to hex
	jmp continuetoconvert

continuetoconvert:	
	mov temp, dx	
	mov ax, cx
	mov cx, 10h
	mul cx
	add ax, temp
	mov cx, ax
	jmp getnum	; check next char

wspace:
	mov onenumberflag, 1	; since wspace has been detected the input does not consist of just one number
	cmp myflag, 1		; check flag
	je wspaceoperand
	jmp wspaceoperator

wspaceoperand:
	push cx
	jmp start

wspaceoperator:
	jmp start

endjump:
	cmp onenumberflag, 0
	je justonenumber	
	jmp output	; dummy statement to jump to end

justonenumber:
	push cx
	jmp output
	
addition:
	pop ax
	pop bx
	add ax, bx
	push ax
	jmp getnum

multiplication:
	pop ax
	pop bx
	mul bx
	push ax
	jmp getnum

division:
	pop bx
	pop ax
	mov dx,0
	div bx
	push ax
	jmp getnum

bitwisexor:
	pop ax
	pop bx
	xor ax, bx
	push ax
	jmp getnum

bitwiseand:
	pop ax
	pop bx
	and ax, bx
	push ax
	jmp getnum

bitwiseor:
	pop ax
	pop bx
	or ax, bx
	push ax
	jmp getnum
	
output:
	pop ax			; pop the result
	mov bx, offset outp+3	; pointer to the end of the output
	mov b[bx], "$"		; put a $ to indicate the end of the string
	jmp printer

printer:
	mov dx, 0	
	mov cx, 10h
	div cx
	dec bx
	cmp counter, 4		; if done with all digits jump towards end
	je printnewline
	inc counter
	cmp dx, 0Ah
	jl outdec
	jmp outhex

outdec:
	add dx, 30h		; convert to ascii chars
	mov [bx], dl
	jmp printer
	
outhex:
	add dx, 37h		; convert to ascii chars
	mov [bx], dl
	jmp printer
printnewline:
	mov ah, 09
	mov dx, offset cr
	int 21h
print:
	mov ah, 09		; print output string
	mov dx, bx
	inc dx
	int 21h
end:	                                                     
	mov ah,04ch		; exit the program with 0
	mov al,00
	int 21h


