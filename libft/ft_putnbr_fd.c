/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 00:03:19 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 15:21:03 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long		number1;

	number1 = (long)n;
	if (number1 < 0)
	{
		write(fd, "-", 1);
		number1 = number1 * (-1);
	}
	if (number1 > 9)
	{
		ft_putnbr_fd((number1 / 10), fd);
		number1 = (number1 % 10);
	}
	ft_putchar_fd(number1 + '0', fd);
}
