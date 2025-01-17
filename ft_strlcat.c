#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (size + ft_strlen(src));
	ft_strlcpy(dest + dest_len, src, size - dest_len);
	return (dest_len + ft_strlen(src));
}
