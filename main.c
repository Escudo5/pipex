/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:55 by smarquez          #+#    #+#             */
/*   Updated: 2025/02/23 12:51:20 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_error(int n)
{
	if (n == 1)
		write(2, "Error, not enough arguments.\n", 29);
	if (n == 2)
		write(2, "Error, Invalid files.\n", 23);
	return(1);
}

int	main(int argc, char **argv, char **env)
{
	int fd[2];
	char **kid_1;
	char **kid_2;
	int status;

	if(argc != 5)
		return(ft_error(1));
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		return(ft_error(2));
	fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd[1] < 0)
	{
		close(fd[0]);
		return(ft_error(2));
	}
	kid_1 = ft_split(argv[2], ' ');
	kid_2 = ft_split(argv[3], ' ');
	status = ft_forks;
	close(fd[0]);
	close(fd[1]);
	//liberamos kids
	return(status);
}

