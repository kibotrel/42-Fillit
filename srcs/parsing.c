/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:01:24 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/26 19:44:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int	check_line(char *line, size_t n)
{
	return ((ft_strlen(line) == n) ? 1 : 0);
}

int	is_validfile(char **file)
{
	int fd;

	if ((fd = open(file, O_RDONLY) < 2))
	{
		ft_putendl("error");
		return (0);
	}
	(void)fd;
	return (1);
}

int check_file(char **line

