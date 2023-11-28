/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anollero <anollero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:28:17 by anollero          #+#    #+#             */
/*   Updated: 2023/11/28 17:22:55 by anollero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	search_path(char **cmd, char **paths, int *local_env)
{
	char	*tmp;
	char	*command;
	int		count;

	count = 0;
	while (paths[count] != NULL)
	{
		tmp = ft_strjoin(paths[count], "/");
		command = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (!access(command, F_OK))
		{
			free(cmd[0]);
			cmd[0] = command;
			return (1);
		}
		free(command);
		count++;
	}
	*local_env = 1;
	return (0);
}

int	is_local(char *cmd)
{
	return (!ft_strncmp(cmd, "/", 1)
		|| !ft_strncmp(cmd, "../", 3)
		|| !ft_strncmp(cmd, "./", 2)
		|| !ft_strncmp(cmd, "~/", 2));
}

void	insert_local(char **cmd)
{
	char	*temp;

	temp = cmd[0];
	cmd[0] = ft_strjoin("./", cmd[0]);
	free(temp);
}

int	no_command(char *command, int local_env)
{
	if (local_env == 1)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		return (0);
	}
	return (1);
}

int	fill_command(char ***command)
{
	if ((*command)[0] == NULL)
	{
		ft_free_split(*command);
		*command = ft_calloc(2, sizeof(char *));
		(*command)[0] = ft_strdup("");
		(*command)[1] = NULL;
		return (1);
	}
	return (0);
}
