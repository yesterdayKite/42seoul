;char	*ft_strcpy(char *dest, char *src)
;{
;	int		i;
;
;	i = 0;
;	while (src[i])
;		dest[i] = src[i];
;	dest[i] = 0;
;	return (dest);
;}

section .text
	global _ft_strcpy

_ft_strcpy:
	xor rcx, rcx
	xor rdx, rdx

strcpy_loop:
	mov dl, byte [rsi + rcx]
	cmp dl, 0
	je strcpy_end
	mov byte [rdi + rcx], dl
	inc rcx
	jmp strcpy_loop

strcpy_end:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	ret
