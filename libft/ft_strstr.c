/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 23:29:30 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 05:36:55 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *small)
{
	size_t	len1;
	int		i;
	int		j;
	int		results;

	len1 = ft_strlen((char *)small);
	i = 0;
	j = 0;
	results = 0;
	if (len1 == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == small[j])
		{
			results = ft_strncmp(&big[i], &small[j], len1);
			if (results == 0)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
