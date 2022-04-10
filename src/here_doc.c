/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:11:01 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 19:35:34 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_here_doc(char *s, t_pipex *vars, int argc)
{
	if (!ft_strncmp(s, HERE_DOC, ft_strlen(s)))
	{
		if (argc < 6)
			return (EXIT_FAILURE);
		vars->here_doc = true;
	}
	else
		vars->here_doc = false;
	return (EXIT_SUCCESS);
}

void	here_doc(t_pipex *vars, char *limiter)
{
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	line = NULL;
	while (!line || ft_strncmp(line, limiter, ft_strlen(line)))
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		write(vars->fd_array[1], line, ft_strlen(line));
		free(line);
	}
	close(vars->fd_array[1]);
	free(limiter);
}
