/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:15:56 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 15:33:12 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(int argc, char **argv)
{
	if (argc < 5)
		return (err_args());
	printf("%d\n", argc);
	return (EXIT_SUCCESS);
}