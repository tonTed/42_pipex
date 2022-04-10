/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:26:12 by tonted            #+#    #+#             */
/*   Updated: 2022/04/09 20:13:42 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

int	err(void)
{
	ft_putstr_fd(BRED ERR_MESS RESET, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	err_message(char *s)
{
	err();
	ft_putendl_fd(s, STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	exit_mess(char *message)
{
	exit(err_message(message));
}

void	exit_errno(int err_no)
{
	perror(strerror(err_no));
	exit(err_no);
}
