/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 23:56:28 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 15:10:19 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long number1;

	number1 = (long)n;
	if (number1 < 0)
	{
		ft_putchar('-');
		number1 = number1 * (-1);
	}
	if (number1 > 9)
	{
		ft_putnbr(number1 / 10);
		number1 = (number1 % 10);
	}
	ft_putchar(number1 + '0');
}
