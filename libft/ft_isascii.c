/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:19:03 by anollero          #+#    #+#             */
/*   Updated: 2023/11/28 17:23:30 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int argument)
{
	int	res;

	res = 1;
	if (!((0 <= argument && argument <= 127)))
		res = 0;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	printf("%d", isascii('+'));
}*/