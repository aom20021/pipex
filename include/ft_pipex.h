/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:35 by anollero          #+#    #+#             */
/*   Updated: 2023/09/19 11:49:32 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex_info
{
	int		file1;
	int		file2;
	char	*command1;
	char	*command2;
	char	**args1;
	char	**args2;
	int		pipein;
	int		pipeout;
}	t_pipex_info;

#endif