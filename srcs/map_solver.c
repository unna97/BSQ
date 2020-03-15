#include "libq.h"

int		min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
}

int		**cache_creator(int row, int col)
{
	int i;
	int **cache;

	i = 0;
	cache = (int**)malloc(sizeof(int*) * (row + 1));
	while (i <= row)
		cache[i++] = (int *)malloc(sizeof(int) * (col + 1));
	cache[row] = NULL;
	return (cache);
}

void	fill_first(int *dim, char **a, char empty, int **cache)
{
	int i;
	int j;

	j = -1;
	while (++j < dim[1])
		cache[0][j] = (int)((a[0][j] == empty));
	i = -1;
	while (++i < dim[0])
		cache[i][0] = (int)((a[i][0] == empty));
}

void	max_asign(int i, int j, int nbr, int *max)
{
	if (!i && !j)
	{
		max[0] = 0;
		max[1] = 0;
		max[2] = nbr;
	}
	else
	{
		if (max[2] < nbr)
		{
			max[0] = i;
			max[1] = j;
			max[2] = nbr;
		}
	}
}

int		*cache(int *dim, char **a, char empty, int i)
{
	int		**cache;
	int		j;
	int		*max;

	cache = cache_creator(dim[0], dim[1]);
	max = (int*)malloc(sizeof(int) * 3);
	max_asign(0, 0, (int)(a[0][0] == empty), max);
	fill_first(dim, a, empty, cache);
	while (++i < dim[0])
	{
		j = 0;
		while (++j < dim[1])
		{
			if (a[i][j] == empty)
			{
				cache[i][j] = 1 + min(cache[i - 1][j - 1], cache[i - 1][j],
									cache[i][j - 1]);
				max_asign(i, j, cache[i][j], max);
			}
			else
				cache[i][j] = 0;
		}
	}
	cache[i] = NULL;
	return (max);
}
