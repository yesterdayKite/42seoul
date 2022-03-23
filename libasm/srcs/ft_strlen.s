;size_t		ft_strlen(char *s)
;{
;	size_t	i;
;
;	i = 0;
;	while (s[i])
;		i++;
;	return (i);
;}

section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax

strlen_loop:
	cmp byte [rdi + rax], 0x0
	je strlen_end
	inc rax
	jmp strlen_loop

strlen_end:
	ret
