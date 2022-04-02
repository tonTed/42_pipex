/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:56:12 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 16:02:39 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_end(t_pipex *vars)
{
	while (vars->amount_cmd--)
		free(vars->cmds->cmd);
	free(vars->cmds);
}

void	free_tab_str(char **tabstr)
{
	u_int32_t	i;

	i = 0;
	while (tabstr[i])
		free(tabstr[i++]);
	free(tabstr);
}