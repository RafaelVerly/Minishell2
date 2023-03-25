/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
	{
		return (NULL);
	}	
	s_len = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (s_len - start >= len)
		sub = malloc((len + 1) * sizeof(char));
	else
		sub = malloc((s_len - start + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, (s + start), (len + 1));
	return (sub);
}

