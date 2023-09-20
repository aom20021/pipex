/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipaux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:02:21 by anollero          #+#    #+#             */
/*   Updated: 2023/09/20 18:16:32 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_pipex.h"
#include "include/libft.h"

/**
 * Libera la memoria de un puntero a punteros de caracteres 
 */
void	ft_free_split(char **tofree)
{
	int	count;

	if (tofree != NULL)
	{
		count = 0;
		while (tofree[count] != NULL)
			free(tofree[count++]);
		free(tofree);
	}
}

/**
 * Abre los archivos de pipex en sus respectivos modos
 * El primero para lectura y el segundo para salida
 * Si el segundo
*/
void	ft_files(char const *argv[], t_pipex_info *info)
{
	if (!access(argv[1], F_OK) && !access(argv[1], R_OK))
		info->file1 = open(argv[1], O_RDONLY);
	else
	{
		perror("no se pudo abrir el fichero de entrada");
		info->file1 = -1;
	}
	if (!access(argv[4], F_OK) && !access(argv[4], W_OK))
		info->file2 = open(argv[4], O_WRONLY | O_TRUNC);
	else if (!access(argv[4], F_OK))
	{
		perror("no se pudo abrir el fichero de salida");
		info->file2 = -1;
	}
	else
		info->file2 = creat(argv[4], 0666);
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
char	*command_return(char *command_0, int found)
{
	if (!found)
		return (NULL);
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
	if (!access(command_split[0], F_OK & X_OK))
		return (command_split[0]);
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
	return (command_return(full_command, found));
}
