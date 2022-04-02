/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:30:37 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 16:41:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err_args(void)
{
	err();
	ft_putstr_fd(ERR_ARGS, STDERR_FILENO);
	return (EXIT_FAILURE);
}
