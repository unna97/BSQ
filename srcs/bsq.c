#include "libq.h"

void	print_array(char **map, int *max, char fill)
{
	int i;
	int j;
	int start_r;
	int	start_c;

	start_r = max[0] - max[2] + 1;
	start_c = max[1] - max[2] + 1;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if ((j >= start_c && j <= max[1]) &&
				(i >= start_r && i <= max[0]))
				write(1, &fill, 1);
			else
				write(1, &(map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	solve(char *file, char **map, char *header, int *dim)
{
	int *max;
	int fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
		map = map_array(fd, dim);
	max = cache(dim, map, header[0], 0);
	print_array(map, max, header[2]);
}

int		bsq(char *file)
{
	int		dim[2];
	char	*header;
	char	**map;
	int		file_row;
	int		fd;

	dim[0] = 0;
	dim[1] = 0;
	fd = open(file, O_RDONLY);
	if (fd)
	{
		header = read_header(fd, file);
		if (header == NULL)
			return (0);
		file_row = ft_atoi(&header);
		if (!(count_r_c(fd, dim, 0, header)))
			return (0);
		if (file_row != dim[0])
			return (0);
		if (close(fd) == -1)
			return (0);
		solve(file, map, header, dim);
	}
	return (1);
}
