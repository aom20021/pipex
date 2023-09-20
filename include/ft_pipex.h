/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:35 by anollero          #+#    #+#             */
/*   Updated: 2023/09/20 16:57:55 by anollero         ###   ########.fr       */
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

void	ft_free_split(char **tofree);
void	ft_files(char const *argv[], t_pipex_info *info);
char	*build_command(char *path, char *command);
char	*command_return(char *command_0, int found);
char	*ft_command(char **path, char **command_split);
void	ft_commands(char const *argv[], char *envp[], t_pipex_info *info);
void	ft_commfiles(char const *arg[], char *env[], t_pipex_info *inf, int *r);
int		ft_execve_first(char *envp[], t_pipex_info *info);
int		ft_execve_second(char *envp[], t_pipex_info *info);
int		main(int argc, char const *argv[], char *envp[]);

#endif