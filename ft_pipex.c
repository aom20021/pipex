/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:35 by anollero          #+#    #+#             */
/*   Updated: 2023/09/19 11:51:40 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_pipex.h"
#include "include/libft.h"

/**
 * Abre los archivos de pipex en sus respectivos modos
 * El primero para lectura y el segundo para salida
 * Si el segundo
*/
void	ft_files(char const *argv[], t_pipex_info *info)
{
	if (!access(argv[1], F_OK & R_OK))
		info->file1 = open(argv[1], O_RDONLY);
	else
		info->file1 = -1;
	if (!access(argv[4], F_OK & W_OK))
		info->file2 = open(argv[4], O_WRONLY);
	else if (!access(argv[4], F_OK))
		info->file2 = -1;
	else
		info->file2 = creat(argv[4], 0777);
}

/**
 * Esta funcion le añade el path al comando
 * para poder ser pasado al execve
*/
char	*build_command(char *path, char *command)
{
	char	*command_slash;
	char	*built_command;

	command_slash = ft_strjoin("/", command);
	built_command = ft_strjoin(path, command_slash);
	free(command_slash);
	return (built_command);
}

/**
 * Evalua si se encontro el comando, si se encontro se envia
 * junto a sus argumentos, si no se devuelve NULL
*/
char	*command_return(char **splitted, char *command_0, int found)
{
	int	count;

	count = 0;
	if (!found)
	{
		while (splitted[count] != NULL)
			free(splitted[count++]);
		free(splitted);
		return (NULL);
	}
	else
		return (command_0);
}

/**
 * Mira si el comando existe en el path
*/
char	*ft_command(char **path, char **command_split)
{
	int		found;
	int		count;
	char	*full_command;

	found = 0;
	count = 0;
	while (path[count] != NULL && !found)
	{
		full_command = build_command(path[count], command_split[0]);
		if (!access(full_command, F_OK & X_OK))
			found = 1;
		else
		{
			free(full_command);
			full_command = NULL;
		}
		count++;
	}
	return (command_return(command_split, full_command, found));
}

/**
 * Saca el path del entorno y mira 
 * si tiene los comandos en alguno de sus directorios
*/
void	ft_commands(char const *argv[], char *envp[], t_pipex_info *info)
{
	int		count;
	void	*path;

	count = 0;
	while (envp[count] != NULL)
	{
		if (ft_strnstr(envp[count], "PATH=", 5))
			path = envp[count] + 5;
		count++;
	}
	info->args1 = ft_split(argv[2], ' ');
	info->args2 = ft_split(argv[3], ' ');
	if (info->args1[0] == NULL || !ft_strncmp(info->args1[0], "./", 2))
		info->command1 = info->args1[0];
	else
		info->command1 = ft_command(ft_split(path, ':'), info->args1);
	if (info->args2[0] == NULL || !ft_strncmp(info->args2[0], "./", 2))
		info->command2 = info->args2[0];
	else
		info->command2 = ft_command(ft_split(path, ':'), info->args2);
}

/**
 * Mete los archivos abiertos y los comandos en el struct pipex_info
*/
void	ft_comm_files(char const *argv[], char *envp[], t_pipex_info *info)
{
	int	inout[2];

	pipe(inout);
	info->pipein = inout[1];
	info->pipeout = inout[0];
	ft_files(argv, info);
	ft_commands(argv, envp, info);
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
		execve(info->command1, info->args1, envp);
		perror("el comando no existe");
		exit(0);
	}
	if (pid == -1)
		exit(0);
	close(info->pipein);
	close(info->file1);
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
		close(2);
		dup(info->file2);
		execve(info->command2, info->args2, envp);
		perror("el comando no existe");
		exit(0);
	}
	if (pid == -1)
		exit(0);
	close(info->pipeout);
	close(info->file2);
	return (pid);
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_pipex_info	*info;
	int				pid1;
	int				pid2;

	info = malloc(sizeof(t_pipex_info));
	if (argc != 5)
		exit(0);
	ft_comm_files(argv, envp, info);
	if (info->file1 != -1 && info->args1[0] != NULL)
		pid1 = ft_execve_first(envp, info);
	if (info->file2 != -1 && info->args2[0] != NULL)
		pid2 = ft_execve_second(envp, info);
	if (info->file1 != -1 && info->args1[0] != NULL)
		waitpid(pid1, NULL, 0);
	if (info->file2 != -1 && info->args2[0] != NULL)
		waitpid(pid2, NULL, 0);
	return (0);
}