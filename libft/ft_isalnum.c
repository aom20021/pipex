/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:43:03 by anollero          #+#    #+#             */
/*   Updated: 2022/09/14 16:19:38 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int argument)
{
	int	res;

	res = 1;
	if (!(('A' <= argument && argument <= 'Z')
			|| ('a' <= argument && argument <= 'z')
			|| ('0' <= argument && argument <= '9')))
			res = 0;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	printf("%d", isalnum('+'));
}*/