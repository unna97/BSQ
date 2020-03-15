#ifndef LIBQ_H
# define LIBQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

int		bsq(char *file);
int		count_r_c(int fd, int *dim, int ret, char *head);
void	ft_error();
int		solve_square(char **map);
char	*read_header(int fd, char *file);
char	**map_array(int fd, int *dim);
int		*cache(int *dim, char **a, char empty, int i);
int		ft_atoi(char **str);
#endif
