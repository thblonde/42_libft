#include "libft.h"

int ft_strslen(char **strs)
{
    int i;

    i = 0;
    while (strs[i])
        i++;
    return (i);
}
