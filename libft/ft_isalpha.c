/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:46:14 by anollero          #+#    #+#             */
/*   Updated: 2022/09/14 16:19:39 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	int	res;

	res = 1;
	if (!(('A' <= argument && argument <= 'Z')
			|| ('a' <= argument && argument <= 'z')))
			res = 0;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	printf("%d", isalpha('2'));
}*/