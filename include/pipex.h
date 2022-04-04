/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:45:05 by tonted            #+#    #+#             */
/*   Updated: 2022/04/02 10:28:50 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "errors.h"


# define PATH "PATH="
# define LEN_PATH 5
# define SEP_PATH ':'
# define DEBUG 1

typedef struct s_pipex
{
	char	**path_bin;
	int		fd_in;
	int		fd_out;
	int		cmds;
	int		*fd_array;
}			t_pipex;

// PARSING
int	parsing(int argc, char **argv, char **envp, t_pipex *vars);

// GETTERS
int	i_file_out(int argc);
int	i_file_in();

// FREE
void	free_end(t_pipex *vars);
void	free_tab_str(char **tabstr);

# include <stdio.h>

#endif

// [-0, =1, 2, 3, =4]