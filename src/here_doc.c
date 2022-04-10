/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:11:01 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 08:33:38 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	is_here_doc(char *s, t_pipex *vars)
{
	if (!(!ft_strncmp(s, HERE_DOC, LEN_HERE_DOC) && strlen(s) == LEN_HERE_DOC))
		vars->here_doc = false;
	vars->here_doc = true;
}