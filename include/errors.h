/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:11 by tonted            #+#    #+#             */
/*   Updated: 2022/03/09 15:32:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../libft/include/libft.h"

# define ERR_MESS "Error.\n"
# define ERR_ARGS "Numbers of arguments must be greater than 3.\n"

int	err(void);
int	err_args(void);

#endif