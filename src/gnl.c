/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:59:28 by tonted            #+#    #+#             */
/*   Updated: 2022/04/10 17:05:56 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	new_ret(char *ret, char *tmp, char *buffer)
{
	u_int32_t	i;

	i = 0;
	while (tmp && tmp[i])
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i++] = buffer[0];
	ret[i] = '\0';
	if (tmp)
		free(tmp);
	if (ret[i - 1] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*ret;
	char	*tmp;
	char	buffer[2];
	ssize_t	i;

	ret = NULL;
	tmp = NULL;
	if (read(fd, ret, 0) < 0)
		return (NULL);
	while (42)
	{
		i = read(fd, buffer, 1);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (ret)
			tmp = ret;
		ret = malloc(sizeof(char) * (ft_strlen(ret) + 2));
		i = 0;
		if (new_ret(ret, tmp, buffer))
			return (ret);
	}
	if (ret)
		return (ret);
	return (NULL);
}
