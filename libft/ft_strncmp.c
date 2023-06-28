/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:28:41 by anollero          #+#    #+#             */
/*   Updated: 2022/09/16 15:44:06 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	count;
	int		ret_value;

	ret_value = 0;
	count = 0;
	while ((s1[count] != '\0')
		&& (s2[count] != '\0')
		&& (ret_value == 0) && count < n)
	{
		if (s1[count] != s2[count])
			ret_value = (unsigned char)s1[count] - (unsigned char)s2[count];
		count++;
	}
	if (ret_value == 0
		&& (s1[count] == '\0' || s2[count] == '\0')
		&& count < n)
		ret_value = (unsigned char)s1[count] - (unsigned char)s2[count];
	return (ret_value);
}
