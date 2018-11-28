/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:59:39 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:19:04 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*str;
	int		counter1;

	counter1 = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[counter1] != '\0' && f)
	{
		str[counter1] = f(s[counter1]);
		counter1++;
	}
	str[counter1] = '\0';
	return (str);
}
