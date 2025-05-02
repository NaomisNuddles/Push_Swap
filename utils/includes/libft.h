/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:43:17 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/05 20:32:06 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

//				MAN FUNC
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *src1, const char *src2, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *src1, const void *src2, size_t n);
char		*ft_strnstr(const char *str, const char *prb, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t mem, size_t n);
char		*ft_strdup(const char *src);

//				42 FUNC
char		*ft_substr(const char *src, unsigned int start, size_t n);
char		*ft_strjoin(const char *src1, const char *src2);
char		*ft_strtrim(const char *src, const char *prb);
char		**ft_split(const char *src, char c);
char		*ft_itoa(int val);
char		*ft_strmapi(const char *src, char (*f)(unsigned int, char));
void		ft_striteri(char *src, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

//				42 FUNC BONUS
t_list		*ft_lstnew(void *ctt);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//				My Bonus
void		ft_mtx_free(char **mtx);
size_t		ft_mtxlen(char **src);
long		ft_atol(const char *str);
#endif //LIBFT_H