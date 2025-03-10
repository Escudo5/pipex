/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:46:50 by smarquez          #+#    #+#             */
/*   Updated: 2025/03/06 16:39:52 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path_list(char **path_list)
{
	int	i;

	i = 0;
	if (!path_list)
		return ;
	while (path_list[i])
	{
		free(path_list[i]);
		i++;
	}
	free(path_list);
}

void	ft_free_kids(char **kid)
{
	int	i;

	i = 0;
	if (!kid)
		return;
	while (kid[i])
	{
		free(kid[i]);
		i++;
	}
	free(kid);
}
