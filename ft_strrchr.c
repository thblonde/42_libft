#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while ((char)s[i])
		i++;
	while (i > 0 && (char)s[i] != (char)c)
		i--;
	if ((char)s[i] == (char)c)
		return (&((char *)s)[i]);
	else
		return (NULL);
}
