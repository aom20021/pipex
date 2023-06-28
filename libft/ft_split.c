/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:55:57 by anollero          #+#    #+#             */
/*   Updated: 2022/12/13 14:09:42 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_all(int words, char **res)
{
	while (words >= 0)
	{
		free(res[words]);
		words--;
	}
	free(res);
	return (NULL);
}

char	**ft_words(char const *s, char c, char **res, int count)
{
	int	words;

	words = 0;
	if (s[count] != c && s[count] != '\0')
		words = 1;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			while (s[count] == c && s[count] != '\0')
				count++;
			if (s[count] != '\0')
				words++;
		}
		if (s[count] != '\0')
			count++;
	}
	res = ft_calloc(words + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	return (res);
}	

char	**ft_alloc(char const *s, char c, char **res, int count)
{
	int	count2;
	int	words;

	count2 = 1;
	words = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			while (s[count] == c && s[count] != '\0')
				count++;
			words++;
		}
		while (s[count] != c && s[count] != '\0')
		{
			count++;
			count2++;
		}
		if (count2 != 1)
			res[words] = ft_calloc(count2, sizeof(char));
		if (res[words] == NULL && s[count] != '\0')
			return (ft_free_all(words, res));
		count2 = 1;
	}
	return (res);
}

char	**ft_fill(char const *s, char c, char **res, int count)
{
	int	words;
	int	count2;

	words = 0;
	count2 = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
		{
			while (s[count] == c && s[count] != '\0')
				count++;
			words++;
		}
		while (s[count] != c && s[count] != '\0')
		{
			res[words][count2] = s[count];
			count++;
			count2++;
		}
		count2 = 0;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	res = NULL;
	count = 0;
	if (!s)
		return (0);
	while (s[count] == c && s[count] != '\0')
		count++;
	res = ft_words(s, c, res, count);
	if (res == NULL)
		return (NULL);
	ft_alloc(s, c, res, count);
	ft_fill(s, c, res, count);
	return (res);
}
