/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:15:46 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/05 13:07:20 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//		MANDATORY

int			ft_atoi(const char *str);
long int	ft_atoli(const char *str);	
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);

void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memchr(const void *str, int c, size_t len);
int			ft_memcmp(const void *str1, const void *str2, size_t len);
void		*ft_memcpy(void	*dst, const	void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *str, int c, size_t len);

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strfjoin(char *s1, char const *s2);


size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char));

int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int c);
int			ft_toupper(int c);

//		MATRIX

char		**ft_mtx_cpy(char **mtx);
int			ft_mtx_line_cnt(char **mtx);
char		**ft_mtx_cut(char **mtx, int cut);
void		ft_mtx_free(char **mtx);

//		LST

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
