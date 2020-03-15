#include "libq.h"

int			ft_atoi(char **str)
{
	int nbr;
	int neg;

	nbr = 0;
	neg = 1;
	while (**str == 32 || (**str > 8 && **str < 14))
		(*str)++;
	if (**str == 45)
	{
		neg = -1;
		(*str)++;
	}
	if (**str == 43 && neg == 1)
		(*str)++;
	while (**str && (**str > 47 && **str < 58))
	{
		nbr = (nbr * 10) + (**str - 48);
		(*str)++;
	}
	return (nbr * neg);
}
