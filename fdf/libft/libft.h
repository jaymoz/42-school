#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0
# define SINT_MAX "2147483647"
# define SINT_MIN "-2147483648"
# define SINT_MAX_P "+2147483647"
# define BUFFER_SIZE 10

typedef struct s_stack
{
	int				number;
	int				order;
	int				keep;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_global
{
	int			size_a;
	int			size_b;
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_global;

typedef struct s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

int				get_next_line(const int fd, char **line);
int				ft_toupper(int letter);
int				ft_atoi_push(char *str);
int				ft_tolower(int num);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
void			ft_bzero(void *b, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int check);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			ft_strclr(char *s);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
char			*ft_strstr(char *haystack, char *needle);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
void			ft_lstclear(t_stack **ptr_lst);
t_stack			*ft_lstlast(t_stack *lst);
t_stack			*ft_lstnew(int number);
int				ft_lstsize(t_stack *lst);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(char *haystack, char *needle);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_nbrlen(int n);
t_stack			*ft_get_param(int argc, char *argv[]);
void			ft_lstfree(t_stack **ptr);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_strdel(char **as);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			ft_strsplit_free(char ***strsplit);
int				ft_isnum(char *s);
int				ft_isint(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_wdcounter(char const *str, char c);

#endif