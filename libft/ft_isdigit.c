/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:38:16 by anollero          #+#    #+#             */
/*   Updated: 2022/09/14 16:19:41 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int argument)
{
	int	res;

	res = 1;
	if (!(('0' <= argument && argument <= '9')))
			res = 0;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	printf("%d", isdigit('2'));
}*/