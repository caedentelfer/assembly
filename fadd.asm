
;******************************************************************
;* floating point addition - Caeden Telfer - 25526693             *
;******************************************************************

global addf

; addf(float a, float b, float *x)
;-----------------------------------------------------------------

%define a    [ebp+8]
%define b    [ebp+12]
%define x    [ebp+16]
%define fr1  [ebp-4] 
%define fr2  [ebp-8] 
%define fr3  [ebp-12] 
%define sg1  [ebp-16]
%define sg2  [ebp-20]
%define sg3  [ebp-24]
%define exp1 [ebp-28]
%define exp2 [ebp-32]
%define exp3 [ebp-36]

addf:

  push ebp
  mov  ebp, esp
  mov  esi, 36
  sub  esp, 26
  mov  eax, a
  cmp  eax, 0x0
  mov  eax, b
  je   .ret
  xor  eax, eax
  mov  eax, b 
  cmp  eax, 0x0
  mov  eax, a
  je   .ret
  xor  eax, eax 	
  mov  eax, a
  cmp  eax, 0x0
  jz   .else

  mov  eax, a
  shr  eax, 31
  mov  sg1, eax
  xor  eax, eax
  mov  eax, a
  and  eax, 0x7fffff
  xor  eax, 0x800000
  mov  fr1, eax
  xor  eax, eax
  mov  eax, a
  shr  eax, 23
  and  eax, 0xff
  mov  exp1, eax
  xor  eax, eax
  jmp  .end_if

.else:
  mov dword exp1, 0x0
  mov dword fr1, 0x0
  xor eax, eax

.end_if:
  mov eax, b
  cmp eax, 0x0
  jz .else2

  shr eax, 31
  mov sg2, eax
  xor eax, eax
  mov eax, b
  and eax, 0x7fffff
  xor eax, 0x800000
  mov fr2, eax
  xor eax, eax
  mov eax, b
  shr eax, 23
  and eax, 0xff
  mov exp2, eax
  xor eax, eax
  jmp .end_if2

.else2:
  mov dword exp2, 0x0
  mov dword fr2, 0x0

.end_if2:	
 mov eax, exp1
 mov edx, exp2
 cmp eax, edx
 jne .next

 mov eax, fr1
 mov edx, fr2
 cmp eax, edx
 jne .next

 mov eax, sg1
 mov edx, sg2
 cmp eax, edx
 mov eax, 0x0
 jne .ret

.next:
 mov eax, exp1
 mov edx, exp2
 mov edi, fr1

.while:
 cmp eax, edx
 jge .end_while
 inc eax
 shr edi, 1
 jmp .while

.end_while:
 mov fr1, edi	
 mov edi, fr2

.while2:
 cmp edx, eax
 jge .end_while2
 inc edx
 shr edi, 1
 jmp .while2

.end_while2:
 mov fr2, edi
 mov exp1, eax
 mov exp2, edx
 mov exp3, eax
 xor eax, eax
 xor edi, edi
 xor edx, edx
 mov eax, a
 cmp eax, 0x0
 jge .end_if3

 xor eax, eax
 mov eax, fr1
 neg eax
 mov fr1, eax
 xor eax, eax

.end_if3:
 mov eax, b
 cmp eax, 0x0
 jge .end_if4

 xor eax, eax
 mov eax, fr2
 neg eax
 mov fr2, eax
 xor eax, eax

.end_if4:
 mov eax, fr1
 mov edx, fr2
 add eax, edx
 mov fr3, eax
 xor eax, eax
 xor edx, edx
 cmp dword fr3, 0x0
 jge .else3

 mov eax, fr3
 neg eax
 mov fr3, eax
 mov dword sg3, 0x1
 xor eax, eax
 jmp .end_if5

.else3:
 mov dword esi, 0x0  
 mov dword sg3, esi

.end_if5:
 mov eax, fr3 	
 xor eax, 0x800000
 mov esi, 0
 cmp eax, esi
 je .add_components
	
.while3:
 mov eax, fr3
 xor eax, 0x800000
 mov esi, 0
 cmp eax, esi
 je .while4

 and eax, 0xff000000
 mov esi, 0
 cmp eax, esi
 je .while4

 shr dword fr3, 1
 inc dword exp3
 jmp .while3

.while4:
 mov esi, 0 
 cmp dword fr3, esi
 je .add_components

 mov eax, fr3
 shr eax, 23
 mov esi, 1
 cmp eax, esi 
 je .add_components

 shl dword fr3, 1
 mov esi, 1
 sub dword exp3, esi
 jmp .while4

.add_components:
 mov ah, sg3
 mov al, exp3
 shl eax, 23
 xor dword fr3, 0x800000
 add eax, fr3
	
.ret:
 mov edx, x
 mov [edx], eax

.exit:
 mov esp, ebp
 pop ebp 
 ret
