/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:56:12 by tonted            #+#    #+#             */
/*   Updated: 2022/04/09 20:24:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab_str(char **tabstr)
{
	u_int32_t	i;

	i = 0;
	while (tabstr[i])
		free(tabstr[i++]);
	free(tabstr);
}

void	free_init(t_pipex *vars)
{
	free_tab_str(vars->path_bin);
	
}