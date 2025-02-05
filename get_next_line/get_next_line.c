#include "../libft.h"

char	*read_file(int fd, char *stash)
{
	char	buf[BUFFER_SIZE];
	int		nread;
	int		i;

	nread = 1;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	while (nread && !(gnl_strchr(buf, '\n')))
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread == -1)
			return (free(stash), NULL);
		buf[nread] = '\0';
		stash = gnl_strjoin(stash, buf);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = gnl_substr(stash, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	tmp = gnl_substr(stash, i + 1, gnl_strlen(stash));
	if (!tmp)
		return (NULL);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), NULL);
	stash = clean_stash(stash);
	return (line);
}
