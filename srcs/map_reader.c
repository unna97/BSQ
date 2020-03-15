#include "libq.h"

char	*read_header(int fd, char *file)
{
	int		ret;
	char	in;
	char	*arr;
	int		i;

	i = 0;
	ret = 0;
	while ((ret = read(fd, &in, 1)) && ret > 0 && in != '\n')
		i++;
	if (close(fd) < 0)
		return (NULL);
	arr = (char *)malloc(i + 1);
	if (!arr)
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	i = 0;
	while ((ret = read(fd, &in, 1)) && ret > 0 && in != '\n')
		arr[i++] = in;
	if (!ret)
		return (NULL);
	arr[++i] = '\0';
	return (arr);
}

int		count_r_c(int fd, int *dim, int ret, char *head)
{
	char	in;
	int		curr_column;

	curr_column = 0;
	while ((ret = read(fd, &in, 1)) && ret > 0)
	{
		if (in == '\n')
		{
			if (curr_column != dim[1] && dim[0] != 0)
				return (0);
			else
			{
				dim[1] = curr_column;
				curr_column = 0;
				(dim[0])++;
			}
		}
		else if (in == head[0] || in == head[1])
			curr_column++;
		else
			return (0);
	}
	return (1 * (dim[0] > 0 && dim[1] > 0));
}
