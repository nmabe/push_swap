#include "libft.h"

char	ft_getchar(void)
{
	char 	c;
	read(0, &c, 1);
	return (c);
}
