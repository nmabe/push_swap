/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:23:25 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 04:56:21 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int counter1;

	counter1 = 0;
	while (s[counter1] != '\0')
	{
		write(fd, &s[counter1], 1);
		counter1++;
	}
}
