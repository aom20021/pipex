/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:16:29 by anollero          #+#    #+#             */
/*   Updated: 2023/07/16 19:01:54 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define LETTERS_UNTIL_PATH 5

typedef struct s_pipex_args
{
	int		infile;
	int		outfile;
	char	*command1;
	char	*command2;
}	t_pipex_args;

char			*ft_path(char *path, char *command);
void			free_paths(char **paths);
int				ft_length(char *command);
void			ft_commands(char *c1, char *c2, char *p, t_pipex_args *arg);
void			ft_files(char *file1, char *file2, t_pipex_args *args);
t_pipex_args	*ft_commands_and_files(char **argv, char **envp);
void			exit_program(void);
int				first_comm(t_pipex_args *args, char *command, char **envp);
void			second_comm(t_pipex_args *args, char *c, int in, char **envp);
int				main(int argc, char *argv[], char *envp[]);

#endif
