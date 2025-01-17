#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	str[ft_strlen(s1)] = '\0';
	return (str);
}
