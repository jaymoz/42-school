/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lross <lross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:46:03 by lross             #+#    #+#             */
/*   Updated: 2022/03/19 18:51:08 by lross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

char			*ft_strnstr(char const *big, char const *little, size_t len);
char			*ft_strrchr(char const *s, int c);
char			*ft_strdup(char *src);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
size_t			ft_strlen(char const *s);
char			*ft_strchr(char const *s, int c);
size_t			ft_strlcpy(char *dest, char const *src, size_t size);

int				ft_atoi(char *str, int *n);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memmove(void *dest, void const *src, size_t num);
void			*ft_memcpy(void *dest, void const *src, size_t num);
int				ft_memcmp(void const *ptr1, void const *ptr2, size_t num);
void			*ft_memchr(void const *ptr, int value, size_t num);
void			*ft_memccpy(void *dest, void const *src, int c, size_t n);

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n, size_t size);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
// size_t			count_w(char const *s, char c);
char			**ft_free(char **s);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));

int				ft_strcmp(char const *s1, char const *s2);

#endif
