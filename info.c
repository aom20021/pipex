/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:30:40 by anollero          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:56 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

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

char	**env(char **env)
{
	int		count;
	char	*path;

	count = 0;
	path = NULL;
	if (env == NULL)
		return (NULL);
	while (env[count] != NULL)
	{
		if (ft_strnstr(env[count], "PATH=", 5))
			path = env[count] + 5;
		count++;
	}
	return (ft_split(path, ':'));
}

void	free_info(t_pipex_info *info)
{
	ft_free_split(info->args1);
	ft_free_split(info->args2);
	free(info);
}

t_pipex_info	*init_info(char **envp)
{
	t_pipex_info	*info;

	info = calloc(1, sizeof(t_pipex_info));
	info->env = env(envp);
	pipe(info->pipe);
	return (info);
}

void	error_msg(char *command, char **env)
{
	if (!access(command, X_OK))
		perror(command);
	else if (env != NULL)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}
