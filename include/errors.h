/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:11 by tonted            #+#    #+#             */
/*   Updated: 2022/04/09 20:34:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../libft/include/libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>

# define ERR_MESS "Error.\n"
# define ERR_PATHBIN "PATH environment variable does not exist"
# define ERR_ARGS_LESS "The amount of arguments must be greater than 4"

int		err(void);
int		err_message(char *s);
void	exit_mess(char *message);
void	exit_errno(int err_no);

#endif