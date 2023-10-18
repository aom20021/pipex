/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:35 by anollero          #+#    #+#             */
/*   Updated: 2023/10/04 16:54:44 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_pipex.h"
#include "include/libft.h"

/**
 * Saca el path del entorno y mira 
 * si tiene los comandos en alguno de sus directorios
*/
void	ft_commands(char const *argv[], char *envp[], t_pipex_info *info)
{
	int		count;
	void	*path;
	char	**path_split;

	count = 0;
	while (envp[count] != NULL)
	{
		if (ft_strnstr(envp[count], "PATH=", 5))
			path = envp[count] + 5;
		count++;
	}
	path_split = ft_split(path, ':');
	info->args1 = ft_split(argv[2], ' ');
	info->args2 = ft_split(argv[3], ' ');
	if (info->args1[0] == NULL || !ft_strncmp(info->args1[0], "./", 2))
		info->command1 = info->args1[0];
	else
		info->command1 = ft_command(path_split, info->args1);
	if (info->args2[0] == NULL || !ft_strncmp(info->args2[0], "./", 2))
		info->command2 = info->args2[0];
	else
		info->command2 = ft_command(path_split, info->args2);
	ft_free_split(path_split);
}

/**
 * Mete los archivos abiertos y los comandos en el struct pipex_info
*/
void	ft_commfiles(char const *argv[], char *env[], t_pipex_info *inf, int *r)
{
	int	inout[2];

	pipe(inout);
	inf->pipein = inout[1];
	inf->pipeout = inout[0];
	ft_files(argv, inf);
	ft_commands(argv, env, inf);
	if (inf->command1 == NULL && ft_strncmp(argv[2], "", 1))
	{
		if (inf->args1 != NULL)
			ft_putstr_fd(inf->args1[0], 2);
		write(2, ": command not found\n", 20);
		ft_free_split(inf->args1);
		inf->args1 = NULL;
	}
	if (inf->command2 == NULL && ft_strncmp(argv[3], "", 1))
	{
		if (inf->args2 != NULL)
			ft_putstr_fd(inf->args2[0], 2);
		write(2, ": command not found\n", 20);
		*r = 127;
		ft_free_split(inf->args2);
		inf->args2 = NULL;
	}
}

/**
 * Ejecuta el primer comando
 */
int	ft_execve_first(char *envp[], t_pipex_info *info)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(0);
		dup(info->file1);
		close(1);
		dup(info->pipein);
		close(info->file2);
		close(info->pipeout);
		execve(info->command1, info->args1, envp);
		if (info->args1 != NULL)
			ft_putstr_fd(info->args1[0], 2);
		write(2, ": command not found\n", 20);
		exit(0);
	}
	if (pid == -1)
		exit(0);
	if (!(info->command1[0] == '.' || info->command1[0] == '/'))
		free(info->command1);
	return (pid);
}

/**
 * Ejecuta el segundo comando
 */
int	ft_execve_second(char *envp[], t_pipex_info *info)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(0);
		dup(info->pipeout);
		close(1);
		dup(info->file2);
		execve(info->command2, info->args2, envp);
		if (info->args2 != NULL)
			ft_putstr_fd(info->args2[0], 2);
		write(2, ": command not found\n", 20);
		exit(127);
	}
	if (pid == -1)
		exit(0);
	if (!(info->command2[0] == '.' || info->command2[0] == '/'))
		free(info->command2);
	return (pid);
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_pipex_info	*info;
	int				pid1;
	int				pid2;
	int				ret;

	info = malloc(sizeof(t_pipex_info));
	if (argc != 5)
		exit(0);
	ft_commfiles(argv, envp, info, &ret);
	if (info->file1 != -1 && info->args1 != NULL && info->args1[0] != NULL)
		pid1 = ft_execve_first(envp, info);
	close(info->pipein);
	close(info->file1);
	if (info->file2 != -1 && info->args2 != NULL && info->args2[0] != NULL)
		pid2 = ft_execve_second(envp, info);
	close(info->pipeout);
	close(info->file2);
	if (info->file1 != -1 && info->args1 != NULL && info->args1[0] != NULL)
		waitpid(pid1, NULL, 0);
	if (info->file2 != -1 && info->args2 != NULL && info->args2[0] != NULL)
		waitpid(pid2, NULL, 0);
	ft_free_split(info->args1);
	ft_free_split(info->args2);
	free(info);
	return (ret);
}
