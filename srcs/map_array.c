#include "libq.h"

char	**array_gen(int row, int col)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc((row + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	while (i < row)
		map[i++] = (char *)malloc((col + 1) * sizeof(char));
	return (map);
}

char	**map_array(int fd, int *dim)
{
	int		i;
	int		j;
	char	**map;
	char	in;

	i = 0;
	map = array_gen(dim[0], dim[1]);
	while (read(fd, &in, 1) && in != '\n')
		i++;
	i = -1;
	while (++i < (dim[0]))
	{
		j = -1;
		while (++j < (dim[1] + 1) && read(fd, &in, 1))
		{
			if (in == '\n')
				map[i][j] = '\0';
			else
				map[i][j] = in;
		}
	}
	map[i] = NULL;
	return (map);
}
