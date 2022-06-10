#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_check_digit(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

#endif
