/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:10:06 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:10:16 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *number)
{
	int i;
	long n;
	int neg;

	i = 0;
	n = 0;
	neg = 1;
	while (number[i] == 32 || (number[i] >= 9 && number[i] <= 13)) 
		i++;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i] == '-')
			neg = 0;
		i++;
	}
	while (number[i] != '\0' && number[i] >= '0' && number[i] <= '9')
	{
		n = (10 * n) + (int)number[i] - 48;
		i++;
	}
	if (neg == 0)
		n = n *(-1);
	return (n);	
}