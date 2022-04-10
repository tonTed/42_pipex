/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:15:56 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 08:34:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errors.h"


int	i_file_in(void)
{
	return (1);
}

int	i_fd_out(int argc)
{
	return (argc - 1);
}

int 	count_cmds(int argc)
{
	return (argc - 3);
}

int		set_fd_array(t_pipex *vars, int cmds){

	int	i;
	int fds[2];

	vars->fd_array = (int *)malloc(sizeof(int) * (vars->cmds) * 2);
	i = 1;
	while (--cmds)
	{
		pipe(fds);
		vars->fd_array[i++] = fds[1];
		vars->fd_array[i++] = fds[0];
	}
	return(i);
}

void	init(t_pipex *vars, int argc, char **argv, char **envp)
{
	vars->cmds = count_cmds(argc);
	vars->path_bin = get_path_bin(envp);
	if (!vars->path_bin)
		exit_mess(ERR_PATHBIN);
	set_fd_array(vars, vars->cmds);
	vars->fd_array[0] = open(argv[i_file_in()], O_RDONLY);
	// vars->fd_array[last_index] = open(argv[i_fd_out(argc)], O_CREAT | O_WRONLY);
}
