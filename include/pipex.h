/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:45:05 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 15:25:47 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "errors.h"

# define PATH "PATH="
# define LEN_PATH 5
# define SEP_PATH ':'

typedef	struct s_cmd
{
	char	*cmd;
	char	*opts;
}			t_cmd;


typedef struct s_pipex
{
	char	*file_in;
	char	*file_out;
	t_cmd	*cmds;
}			t_pipex;

// PARSING
int	parsing(int argc, char **argv);

# include <stdio.h>

#endif