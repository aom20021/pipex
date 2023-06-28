/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:36:27 by anollero          #+#    #+#             */
/*   Updated: 2022/10/08 14:50:27 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		count;

	if (!s)
		return (0);
	count = 0;
	res = (char *)malloc(ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		res[count] = f(count, s[count]);
		count++;
	}
	res[count] = '\0';
	return (res);
}
