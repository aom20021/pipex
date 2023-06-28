/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:55:33 by anollero          #+#    #+#             */
/*   Updated: 2022/10/02 15:50:56 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_exceptions(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		count;

	if (n == 0 || n == -2147483648)
		ft_exceptions(n, fd);
	count = 0;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(fd, "-", 1);
	}
	while (n != 0 && n != -2147483648)
	{
		str[count] = (n % 10) + 48;
		count++;
		n = n / 10;
	}
	str[count] = '\0';
	count--;
	while (count >= 0 && n != -2147483648)
	{
		write(fd, &str[count], 1);
		count--;
	}
}
