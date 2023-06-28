/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:13:49 by anollero          #+#    #+#             */
/*   Updated: 2022/10/02 16:06:33 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int			pointer;
	const char	*ret;
	char		c2;

	c2 = c;
	ret = 0;
	pointer = 0;
	while (str[pointer] != '\0')
	{
		if (str[pointer] == c2)
			ret = &str[pointer];
		pointer++;
	}
	if (str[pointer] == c2)
		ret = &str[pointer];
	return (((char *)ret));
}
