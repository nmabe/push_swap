/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:12:05 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 09:54:56 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		count;

	count = 0;
	while (s1[count] == s2[count] && count < n && s1[count] != '\0')
		count++;
	if (count == n)
		return ((unsigned char)s1[count - 1] - (unsigned char)s2[count - 1]);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
