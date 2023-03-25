/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:56:11 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 21:04:27 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	quant_words(const char *s, char c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 1;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i] == c)
		i++;
	while (i < ft_strlen(s))
	{	
		if (s[i] != c)
		{	
			count += 1;
			while (s[i] != c && i < ft_strlen(s))
				i++;
		}
	i++;
	}	
	return (count);
}

static char	**add_str(char **array_str, char const *s, char c)
{
	int		j;
	size_t	i;
	int		words;

	j = 0;
	words = quant_words(s, c);
	while (j < words - 1 && ft_strlen(s) != 0)
	{
		i = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			i++;
		}
		if (i > 0)
		{
			array_str[j] = malloc((i + 1) * sizeof(char));
			ft_strlcpy(array_str[j], (s - i), i + 1);
			j++;
		}
		while (*s == c)
			s++;
	}	
	return (array_str);
}

char	**ft_split(char const *s, char c)
{
	char	**array_str;	
	int		words;

	if (s == NULL)
		return (NULL);
	words = quant_words(s, c);
	array_str = malloc((words) * sizeof(char *));
	if (!array_str)
		return (NULL);
	array_str = add_str(array_str, s, c);
	array_str[words - 1] = NULL;
	return (array_str);
}