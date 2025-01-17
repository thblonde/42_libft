#include "libft.h"

static int	is_in_set(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && is_in_set((char *)set, s1[start]) == 1)
		start++;
	while (end > start && is_in_set((char *)set, s1[end - 1]) == 1)
		end--;
	return (ft_substr(s1, start, end - start));
}
