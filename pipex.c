/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:16:22 by anollero          #+#    #+#             */
/*   Updated: 2023/06/28 16:31:35 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

/**
 * @brief this function checks if the path passed on the first argument
 * contains the command passed on the second argument
 * @param path the candidate to be the full path
 * @param command the command
 * @return the full path of the command or NULL in case of faillure
 */
char	*ft_path(char *path, char *command)
{
	char	*path_with_slash;
	char	*full_path;

	path_with_slash = ft_strjoin(path, "/");
	full_path = ft_strjoin(path_with_slash, command);
	free(path_with_slash);
	if (access(full_path, F_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

/**
 * @brief this function frees the candidates to be a path
 * 
 * @param paths the array of strings
 */
void	free_paths(char **paths)
{
	char	**iterator;

	iterator = paths;
	while (*iterator)
		iterator++;
	free(paths);
}

/**
 * @brief this function retrieves the length of a command
 * without the parameters
 * @param command 
 * @return the length of the command
 */
int	ft_length(char *command)
{
	int	count;

	count = 0;
	while (command[count] != ' ' && command[count] != '\0')
		count++;
	return (count);
}

/**
 * @brief this function adds the full path of both commands or NULL 
 * if they doesnt exist to the args struct
 * @param comm1 the first command
 * @param comm2 the second command
 * @param path the path variable from the environment
 * @param args a struct that stores the full path of the commands and the fds
 */
void	ft_commands(char *comm1, char *comm2, char *path, t_pipex_args *args)
{
	char	**possible_paths;
	char	**paths_iter;
	char	*path1;
	char	*path2;

	possible_paths = ft_split(path + LETTERS_UNTIL_PATH, ':');
	paths_iter = possible_paths;
	path2 = NULL;
	path1 = NULL;
	while (*paths_iter)
	{
		if (path1 == NULL)
			path1 = ft_path(*paths_iter, ft_substr(comm1, 0, ft_length(comm1)));
		if (path2 == NULL)
			path2 = ft_path(*paths_iter, ft_substr(comm2, 0, ft_length(comm2)));
		if ((path1 != NULL) && (path2 != NULL))
			break ;
		paths_iter++;
	}
	free_paths(possible_paths);
	args->command1 = path1;
	args->command2 = path2;
}

/**
 * @brief this function adds the file descriptor of the infile and outfile
 * or -1 to the args struct
 * @param file1 the first file
 * @param file2 the second file
 * @param args a struct that stores the full path of the commands and the fds
 */
void	ft_files(char *file1, char *file2, t_pipex_args *args)
{
	int	fd1;
	int	fd2;

	fd1 = open(file1, O_RDONLY);
	if (fd1 < 0)
		ft_putstr_fd("pipex: no existe el fichero de entrada", 2);
	fd2 = open(file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd2 < 0)
		ft_putstr_fd("pipex: no existe el fichero de salida", 2);
	args->infile = fd1;
	args->outfile = fd2;
}

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
 * @brief this function executes the second command of the pipe
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
	return (0);
}
