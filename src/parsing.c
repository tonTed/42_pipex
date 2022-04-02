/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:15:56 by tonted            #+#    #+#             */
/*   Updated: 2022/03/13 11:50:03 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	i_file_in(void)
{
	return (1);
}

int	i_file_out(int argc)
{
	return (argc - 1);
}

int count_cmds(int argc)
{
	return (argc - 3);
}

int	parsing(int argc, char **argv, char **envp, t_pipex *vars)
{	
	if (argc < 5)
		return (err_args());
	if (access(argv[i_file_in()], R_OK))
		return (err_message(strerror(errno)));
	if (!access(argv[i_file_out(argc)], F_OK))
		if (access(argv[i_file_out(argc)], W_OK))
			return (err_message(strerror(errno)));
	// vars->path_bin = get_path_bin(envp);
	return (EXIT_SUCCESS);
}
