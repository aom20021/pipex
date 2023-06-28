/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:50 by anollero          #+#    #+#             */
/*   Updated: 2022/10/02 15:51:48 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dupped;
	int		count;

	len = ft_strlen(s);
	count = 0;
	dupped = (char *)malloc(len * sizeof(char) + 1);
	if (dupped == 0)
		return (0);
	while (s[count] != '\0')
	{
		dupped[count] = s[count];
		count++;
	}
	dupped[count] = '\0';
	return (dupped);
}
