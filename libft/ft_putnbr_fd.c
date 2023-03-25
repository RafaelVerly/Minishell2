/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:30:05 by rverly            #+#    #+#             */
/*   Updated: 2022/06/19 20:33:06 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_n(int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	tfr_char(int len, int n, int fd)
{
	int		i;
	int		dvs;
	char	letter;

	while (len > 0)
	{
		i = 1;
		dvs = 1;
		while (i++ < len)
			dvs *= 10;
		letter = (n / dvs) % 10 + '0';
		write(fd, &letter, 1);
		len--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{	
			write(fd, "2147483648", 10);
			return ;
		}
		n = n * -1;
	}
	if (n != -2147483648)
		tfr_char(size_n(n), n, fd);
}