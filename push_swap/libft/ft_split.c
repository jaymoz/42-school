#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static char	*dup_of_word(const char *str, int begin, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc ((end - begin + 1) * sizeof(char));
	while (begin < end)
		word[i++] = str[begin++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || split == NULL)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while ((int)i <= ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || (int)i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j++] = dup_of_word(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
