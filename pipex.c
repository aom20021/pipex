/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:58:06 by anollero          #+#    #+#             */
/*   Updated: 2024/03/21 17:24:58 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void	commands(t_pipex_info *inf, const char *command1, const char *command2)
{
	inf->args1 = ft_split(command1, ' ');
	inf->args2 = ft_split(command2, ' ');
	if (inf->env != NULL)
	{
		if (!fill_command(&inf->args1) && !is_local(inf->args1[0]))
			search_path(inf->args1, inf->env, &inf->local_env1);
		if (!fill_command(&inf->args2) && !is_local(inf->args2[0]))
			search_path(inf->args2, inf->env, &inf->local_env2);
	}
	else
	{
		if (!fill_command(&inf->args1)
			&& !is_local(inf->args1[0]) && !access(command1, F_OK))
			insert_local(inf->args1);
		if (!fill_command(&inf->args2)
			&& !is_local(inf->args2[0]) && !access(command2, F_OK))
			insert_local(inf->args2);
	}
}

void	files(t_pipex_info *info, const char *file1, const char *file2)
{
	info->file1 = open(file1, O_RDONLY);
	if (info->file1 == -1)
		perror(file1);
	info->file2 = open(file2, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (info->file2 == -1)
		perror(file2);
}

int	first_child(t_pipex_info *info)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(0);
		dup(info->file1);
		close(1);
		dup(info->pipe[1]);
		close(info->file2);
		close(info->pipe[0]);
		execve(info->args1[0], info->args1, info->env);
		error_msg(info->args1[0], info->env);
		exit(127);
	}
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	return (pid);
}

int	second_child(t_pipex_info *info)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(0);
		dup(info->pipe[0]);
		close(1);
		dup(info->file2);
		execve(info->args2[0], info->args2, info->env);
		error_msg(info->args2[0], info->env);
		exit(127);
	}
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	return (pid);
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_pipex_info	*info;

	if (argc != 5)
		exit(0);
	info = init_info(envp);
	files(info, argv[1], argv[4]);
	commands(info, argv[2], argv[3]);
	if (info->file1 != -1 && no_command(info->args1[0], info->local_env1))
		info->pid1 = first_child(info);
	close(info->pipe[1]);
	close(info->file1);
	if (info->file2 != -1 && no_command(info->args2[0], info->local_env2))
		info->pid2 = second_child(info);
	close(info->file2);
	close(info->pipe[0]);
	if (info->pid1 != -1)
		waitpid(info->pid1, NULL, 0);
	if (info->pid2 != -1)
	{
		waitpid(info->pid2, NULL, 0);
		exit(WEXITSTATUS(info->pid2));
	}
	free_info(info);
	return (127);
}
