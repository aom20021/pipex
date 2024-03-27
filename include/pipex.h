/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:35 by anollero          #+#    #+#             */
/*   Updated: 2024/03/21 17:45:44 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex_info
{
	int		file1;
	int		file2;
	char	**args1;
	char	**args2;
	int		pipe[2];
	char	**env;
	int		pid1;
	int		pid2;
	int		local_env1;
	int		local_env2;
	int		*return_status_2;
}	t_pipex_info;

void			ft_free_split(char **tofree);
char			**env(char **env);
void			error_msg(char *command, char **env);
int				fill_command(char ***command);
int				no_command(char *command, int local_env);
int				search_path(char **cmd, char **paths, int *local_env);
int				is_local(char *cmd);
void			insert_local(char **cmd);
void			commands(t_pipex_info *inf, const char *command1,
					const char *command2);
void			files(t_pipex_info *info, const char *file1, const char *file2);
int				first_child(t_pipex_info *info);
int				second_child(t_pipex_info *info);
t_pipex_info	*init_info(char **envp);
void			free_info(t_pipex_info *info);
int				main(int argc, char const *argv[], char *envp[]);

#endif