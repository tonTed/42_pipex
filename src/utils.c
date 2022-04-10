/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:44:25 by tonted            #+#    #+#             */
/*   Updated: 2022/04/09 19:51:33 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fd_read_end(int fds[2])
{
	return (fds[0]);
}

int	fd_write_end(int fds[2])
{
	return (fds[1]);
}

char	*get_path_exec(char **path_bin, char *cmd)
{
	u_int32_t	i;
	char		*cmd_path;
	char		*tmp;

	if (ft_ischarinstr('/', cmd))
		return(cmd);	
	i = 0;
	while (path_bin[i])
	{
		tmp = ft_strjoin(path_bin[i], "/");
		cmd_path = ft_strjoin(tmp, ft_split(cmd, ' ')[0]);
		free(tmp);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (cmd);
}

char	**get_path_bin(char **envp)
{
	while (*envp)
	{
		if (!(ft_strncmp(PATH, *envp, LEN_PATH)))
			return(ft_split(&(*envp)[LEN_PATH], SEP_PATH));
		envp++;
	}
	return (NULL);
}
