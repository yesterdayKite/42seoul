/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopark <yopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 15:20:28 by yopark            #+#    #+#             */
/*   Updated: 2020/04/24 15:56:41 by yopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define ERROR		-1

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_abs(int nbr);
int					ft_atoi(const char *str);
void				ft_bzero(void *ptr, size_t byte);
void				*ft_calloc(size_t cnt, size_t per);
int					ft_isalnum(int arg);
int					ft_isalpha(int arg);
int					ft_isascii(int arg);
int					ft_isdigit(int arg);
int					ft_isprint(int arg);
int					ft_issapce(int arg);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *dst, const void *src,
						int arg, size_t byte);
void				*ft_memchr(const void *ptr, int arg, size_t byte);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t byte);
void				*ft_memcpy(void *dst, const void *src, size_t byte);
void				*ft_memmove(void *dst, const void *src, size_t byte);
void				*ft_memset(void *ptr, int value, size_t byte);
long long			ft_power(int n, int power);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *s);
size_t				ft_size_max(size_t a, size_t b);
size_t				ft_size_min(size_t a, size_t b);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int arg);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *str1, const char *str2, size_t size);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t size);
char				*ft_strrchr(const char *str, int arg);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int arg);
int					ft_toupper(int arg);

#endif
