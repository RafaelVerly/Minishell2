/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ctr;

	ctr = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ctr)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (ctr == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}