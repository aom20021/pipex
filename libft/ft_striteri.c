/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:41:23 by anollero          #+#    #+#             */
/*   Updated: 2022/10/08 14:52:02 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	count;

	if (s)
	{
		count = 0;
		while (s[count] != '\0')
		{
			f(count, &s[count]);
			count++;
		}
	}
}
