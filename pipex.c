/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:16:22 by anollero          #+#    #+#             */
/*   Updated: 2023/07/16 18:59:37 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief adds the paths of the commands and the fds
 * of the files to the args struct
 * @param argv the list of the arguments of the program
 * @param envp a pointer to the environment
 * @return the new args struct
 */
t_pipex_args	*ft_commands_and_files(char **argv, char **envp)
{
	t_pipex_args	*args;
	char			**envp_iter;

	args = malloc(sizeof(t_pipex_args));
	envp_iter = envp;
	while (*envp_iter)
	{
		if (ft_strncmp("PATH=", *envp_iter, 5) == 0)
		{
			ft_commands(argv[2], argv[3], *envp_iter, args);
			break ;
		}
		envp_iter++;
	}
	ft_files(argv[1], argv[4], args);
	return (args);
}

/**
 * @brief this function exits the program
 */
void	exit_program(void)
{
	exit(0);
}

/**
 * @brief this function executes the first command of the pipe
 * 
 * @param args the args struct that has the path of the command and the infile
 * @param command the command with its parameters
 * @param envp a pointer to the environment
 * @return the pipe that has the output of the command
 */
int	first_comm(t_pipex_args *args, char *command, char **envp)
{
	int			pid;
	int			pipe_commands[2];
	char *const	*command_args;

	pipe(pipe_commands);
	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid > 0)
	{
		close(pipe_commands[1]);
		return (pipe_commands[0]);
	}
	else
	{
		close(STDIN_FILENO);
		if (args->infile == -1)
			exit(-1);
		dup(args->infile);
		close(STDOUT_FILENO);
		dup(pipe_commands[1]);
		command_args = ft_split(command, ' ');
		execve(args->command1, command_args, envp);
		exit(0);
	}
}

/**
 * @brief this function executes the second command of the pipe after the
 * first comand has ended
 * 
 * @param args the args struct that has the path of the command and the infile
 * @param command the command with its parameters
 * @param inpipe the input fd for the new command
 * @param envp a pointer to the environment
 * @return the pipe that has the output of the command
 */
void	second_comm(t_pipex_args *args, char *comm, int in, char **envp)
{
	char *const	*command_args;

	wait(NULL);
	if (args->outfile == -1)
		exit(-1);
	else
	{
		close(STDOUT_FILENO);
		dup(args->outfile);
	}
	if (in != -1)
	{
		close(STDIN_FILENO);
		dup(in);
	}
	command_args = ft_split(comm, ' ');
	execve(args->command2, command_args, envp);
}

/**
 * @brief pipex logic
 * 
 * @param argc the number of the arguments of the function
 * @param argv the arguments of the function
 * @param envp a pointer to the environment
 */
int	main(int argc, char *argv[], char *envp[])
{
	t_pipex_args	*args;
	int				outpipe;

	if (argc != 5)
	{
		ft_putstr_fd("pipex: no se han introducido 5 parametros", 2);
		return (-1);
	}
	if (envp == NULL)
	{
		ft_putstr_fd("pipex: no hay environment", 2);
		return (-1);
	}
	args = ft_commands_and_files(argv, envp);
	if (args->command1 == NULL)
		ft_putstr_fd("pipex: no existe el primer comando\n", 2);
	if (args->command2 == NULL)
		ft_putstr_fd("pipex: no existe el segundo comando\n", 2);
	outpipe = first_comm(args, argv[2], envp);
	if (args->command1 == NULL)
		outpipe = -1;
	second_comm(args, argv[3], outpipe, envp);
	exit_program();
}
