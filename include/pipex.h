/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:45:05 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 08:35:25 by tonted           ###   ########.fr       */
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

# define HERE_DOC "here_doc"
# define LEN_HERE_DOC 8
# define DEBUG 1

typedef struct s_pipex
{
	char	**path_bin;
	int		fd_in;
	int		cmds;
	int		*fd_array;
	bool	here_doc;
}			t_pipex;

// 
void	init(t_pipex *vars, int argc, char **argv, char **envp);

// returns the read end of the pipe
int	fd_read_end(int fds[2]);

// returns the write end of the pipe
int	fd_write_end(int fds[2]);

// returns the absolute path of the cmd to execute if exists,
// otherwise returns `cmd`.
char	*get_path_exec(char **path_bin, char *cmd);

// returns a tab of char* with the absoulte path oh the bin folder.
char	**get_path_bin(char **envp);

// free all variable have been malloc.
void	free_init(t_pipex *vars);

// returns the index of the output file in args.
int		i_fd_out(int argc);

//
void	is_here_doc(char *s, t_pipex *vars);


# include <stdio.h>

#endif

// [-0, =1, 2, 3, =4]