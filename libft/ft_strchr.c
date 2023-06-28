/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:53:21 by anollero          #+#    #+#             */
/*   Updated: 2022/09/21 19:09:53 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		pointer;
	char	c2;

	c2 = c;
	pointer = 0;
	while (str[pointer] != '\0' && str[pointer] != c2)
	{
		pointer++;
	}
	if (c2 != '\0' && str[pointer] == '\0')
		return (0);
	return ((char *)(str + pointer));
}
