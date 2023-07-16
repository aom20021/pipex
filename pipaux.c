/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipaux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:55:21 by anollero          #+#    #+#             */
/*   Updated: 2023/07/16 18:59:41 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
