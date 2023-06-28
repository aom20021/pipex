/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:27:06 by anollero          #+#    #+#             */
/*   Updated: 2022/09/14 16:19:41 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argument)
{
	int	res;

	res = 1;
	if (!((32 <= argument && argument <= 126)))
			res = 0;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	printf("%d", isprint('2'));
}*/