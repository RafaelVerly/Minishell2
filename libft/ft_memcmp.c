/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*str_aux1;
	unsigned char	*str_aux2;

	str_aux1 = (unsigned char *)str1;
	str_aux2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str_aux1[i] != str_aux2[i])
			return (str_aux1[i] - str_aux2[i]);
		i++;
	}
	return (0);
}