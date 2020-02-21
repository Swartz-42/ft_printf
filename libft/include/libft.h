/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:45:44 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 16:34:54 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
int				ft_base(unsigned long nbr, char *base);
int				ft_base_ld(long nbr, char *base);
int				ft_base_ui(unsigned int nbr, char *base);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_comp(char text, char *charset);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(long int n);
char			*ft_itoabase(long int n, char *charset);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memccpy(void *restrict dst, const void *restrict src,
							int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
							size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_base(unsigned long nbr, char *base);
void			ft_putnbr_fd(long n, int fd);
void			ft_putnchar_fd(char c, int n, int fd);
void			ft_putnstr_fd(char *str, int n, int fd);
int				ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char const c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
							size_t size);
size_t			ft_strlcpy(char *restrict dst, const char *restrict src,
							size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
