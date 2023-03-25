/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && (i < n))
	{
		s1++;
		s2++;
		if (*s1 == '\0' || *s2 == '\0')
			break ;
		i++;
	}
	if (*s1 != *s2)
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}	
	return (0);
}