/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:56:11 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 21:04:27 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_n(unsigned int n)
{
	unsigned int	count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}	
	return (count);
}

static void	add_str(char *str, size_t n_len, unsigned int n)
{
	char	un;

	while (n_len > 0 && str[n_len - 1] != '-')
	{
		un = (char)(n % 10) + '0';
		n_len--;
		str[n_len] = un;
		n = n / 10;
	}	
}

char	*ft_itoa(int n)
{
	size_t		n_len;
	char		*str;

	if (n >= 0)
	{	
		n_len = len_n(n);
		str = (char *) ft_calloc((n_len + 1), sizeof(char));
	}
	else
	{
		n = n * -1;
		n_len = len_n(n);
		str = (char *) ft_calloc((n_len + 2), sizeof(char));
		if (!str)
			return (NULL);
		n_len = n_len + 1;
		str[0] = '-';
	}
	if (!str)
		return (NULL);
	add_str(str, n_len, n);
	return (str);
}