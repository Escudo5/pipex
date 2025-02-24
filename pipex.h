/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:22:34 by smarquez          #+#    #+#             */
/*   Updated: 2025/02/24 12:25:42 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIEPEX_H

# include "custom-libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

int ft_fork(int *fd, char **kid_1, char **command_2, char **env);
void ft_free_kids(char **kid);
void free_path_list(char **path_list);
int ft_error(int n);
char *ft_get_path_command(char **command, char **env, char *path_mid);
char *ft_check_command(char **path_list, char *path_mid, char *command);

#endif


