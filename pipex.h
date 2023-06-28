/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:16:29 by anollero          #+#    #+#             */
/*   Updated: 2023/06/28 14:12:03 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define LETTERS_UNTIL_PATH 5

typedef struct s_pipex_args
{
	int		infile;
	int		outfile;
	char	*command1;
	char	*command2;
}	t_pipex_args;

int	main(int argc, char *argv[], char *envp[]);

#endif
