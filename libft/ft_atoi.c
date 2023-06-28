/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:27:41 by anollero          #+#    #+#             */
/*   Updated: 2022/12/13 14:07:31 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spaces(const char *arr, int *sign)
{
	int	ret;

	ret = 0;
	*sign = 1;
	while (*(arr + ret) == ' ' || (*(arr + ret) >= 9 && *(arr + ret) <= 13))
		ret++;
	return (ret);
}

int	ft_is_number(char nb)
{
	if (('0' <= nb && nb <= '9'))
		return (1);
	else
		return (0);
}

size_t	ft_atoi(const	char *nptr)
{
	int						count;
	unsigned long long int	number;
	int						sign;

	count = ft_spaces(nptr, &sign);
	if (nptr[count] == '-')
	{	
		sign = -1;
		count++;
	}
	else if (nptr[count] == '+')
		count++;
	number = 0;
	while (ft_is_number(*(count + nptr)) && *(count + nptr) != '\0')
	{
		number = number * 10;
		number = number + (*(nptr + count) - 48);
		count++;
	}
	return (number * sign);
}
