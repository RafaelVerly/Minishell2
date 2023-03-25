/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char	*dst_aux;
	unsigned char	*src_aux;

	if (!dst && !src)
		return (NULL);
	dst_aux = (unsigned char *)dst;
	src_aux = (unsigned char *)src;
	if (src < dst)
	{
		while (num > 0)
		{
			num--;
			dst_aux[num] = src_aux[num];
		}
	}
	else
		ft_memcpy(dst_aux, src_aux, num);
	return (dst);
}

