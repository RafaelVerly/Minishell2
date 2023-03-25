/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *hk, const char *nd, size_t len)
{
	size_t	i;
	size_t	size;

	if (nd[0] == '\0')
		return ((char *) hk);
	i = 0;
	size = ft_strlen(nd);
	while (hk[i] != '\0' && size <= len - i)
	{
		if (!ft_strncmp(hk + i, nd, size))
			return ((char *)&(hk[i]));
		i++;
	}
	return (NULL);
}