/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:41:26 by smarquez          #+#    #+#             */
/*   Updated: 2025/02/28 18:29:53 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_check_command(char **path_list, char *path_mid, char *command)
{
	int		i;
	char	*path_end;

	i = -1;
	while (path_list[++i])
	{
		path_mid = ft_strjoin(path_list[i], "/");
		path_end = ft_strjoin(path_mid, command);
		free(path_mid);
		if (access(path_end, X_OK) == 0)
		{
			free_path_list(path_list);
			return (path_end);
		}
		free(path_end);
	}
	return (NULL);
}

char	*ft_get_path_command(char **command, char **env, char *path_mid)
{
	int		i;
	char	*path;
	char	**path_list;

	if (ft_strchr(command[0], '/'))
		if (access(command[0], X_OK) == 0)
			return (ft_strdup(command[0]));
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path_list = ft_split(env[i], ':');
			path = ft_check_command(path_list, path_mid, command[0]);
			if (path)
				return (path);
		}
	}
	free_path_list(path_list);
	return (NULL);
}
