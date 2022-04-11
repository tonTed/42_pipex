/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:26:20 by tonted            #+#    #+#             */
/*   Updated: 2022/04/11 10:11:53 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "errors.h"

void	open_output(t_pipex *vars, int argc, char **argv)
{
	if (!vars->here_doc)
		vars->fd_array[i_fd_out(vars->cmds * 2)] = open(argv[i_fd_out(argc)],
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		vars->fd_array[i_fd_out(vars->cmds * 2)] = open(argv[i_fd_out(argc)],
				O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (vars->fd_array[i_fd_out(argc)] == -1)
	{
		free_init(vars);
		exit_errno(errno);
	}
}

bool	last_cmd(int i, int cmd)
{
	return (i + 1 == cmd);
}

char	*get_cmd(char **argv, t_pipex vars)
{
	return (argv[vars.index_forks + 2]);
}

pid_t	fork_execute(t_pipex vars, char **argv, int argc)
{
	pid_t	id;

	while (vars.index_forks < vars.cmds)
	{		
		if (last_cmd(vars.index_forks, vars.cmds))
			open_output(&vars, argc, argv);
		id = fork();
		if (id == 0)
		{	
			dup2(fd_read_end(vars), STDIN_FILENO);
			dup2(fd_write_end(vars), STDOUT_FILENO);
			execve(get_path_exec(vars.path_bin, get_cmd(argv, vars)),
				ft_split(get_cmd(argv, vars), ' '), NULL);
			perror(strerror(errno));
			exit(1);
		}
		else
			close(fd_write_end(vars));
		vars.index_forks++;
	}
	return (id);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	vars;

	if (argc < 5 || (set_here_doc(argv[1], &vars, argc)))
		exit_mess(ERR_ARGS_LESS);
	init(&vars, argc, argv, envp);
	if (vars.here_doc && BONUS)
		here_doc(&vars, argv[2]);
	waitpid(fork_execute(vars, argv, argc), NULL, 0);
	free_init(&vars);
	return (0);
}
