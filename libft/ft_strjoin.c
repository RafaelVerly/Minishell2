/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1len;
	int		s2len;
	int		i;

	if (!s1)
		return (NULL);
	i = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = malloc((s1len + s2len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (++i < s1len)
		newstr[i] = s1[i];
	while (*s2 != '\0')
	{
		newstr[i++] = *s2;
		s2++;
	}
	newstr[i] = '\0';
	return (newstr);
}