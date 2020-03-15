#include "libq.h"

void	file(void)
{
	int		fd;
	char	ch;

	fd = open("xyz.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (read(STDIN_FILENO, &ch, 1) > 0)
		write(fd, &ch, 1);
	close(fd);
}

int		main(int argc, char **argv)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (flag)
				write(1, "\n", 1);
			if (!(bsq(argv[i])))
				ft_error();
			flag++;
		}
	}
	else
	{
		file();
		if (!(bsq("xyz.txt")))
			ft_error();
	}
	return (0);
}
