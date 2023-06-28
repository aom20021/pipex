/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:50:21 by anollero          #+#    #+#             */
/*   Updated: 2022/10/08 14:50:05 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_aux(int n)
{
	char	*res;

	if (n == 0)
	{
		res = (char *)malloc(2);
		if (res == NULL)
			return (NULL);
		res[0] = 48;
		res[1] = '\0';
		return (res);
	}
	else
	{
		res = (char *)malloc(12);
		if (res == NULL)
			return (NULL);
		ft_strlcpy(res, "-2147483648", 12);
		return (res);
	}
}

void	ft_sign_alloc(int *aux, int *n, char *sign, int *alloc)
{
	*(alloc) = 1;
	if (*n < 0)
	{
		*(sign) = '-';
		*n = -(*(n));
		*(alloc) = *(alloc) + 1;
	}
	else
		*(sign) = '\0';
	while (*aux != 0)
	{
		*aux = *(aux) / 10;
		*(alloc) = *(alloc) + 1;
	}
}

char	*ft_itoa(int n)
{
	char	sign;
	int		alloc;
	int		aux;
	char	*res;

	aux = n;
	if (n == -2147483648 || n == 0)
		return (ft_itoa_aux(n));
	ft_sign_alloc(&aux, &n, &sign, &alloc);
	res = (char *)malloc(alloc * sizeof(char));
	if (res == NULL)
		return (NULL);
	aux = n;
	res[alloc - 1] = '\0';
	alloc = alloc - 2;
	while (aux != 0)
	{
		res[alloc] = (aux % 10) + 48;
		aux = aux / 10;
		alloc--;
	}
	if (sign == '-')
		res[alloc] = sign;
	return (res);
}
