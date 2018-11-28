/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:01:24 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/28 16:26:32 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int	check_piece(char *tab[4])
{
	int		x;
	int		y;
	int		count;

	x = -1;
	count = 0;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (tab[x][y] == '.' || tab[x][y] == '#')
			{
				if (tab[x][y] == '#')
					count++;
			}
			else
				return (0);
		}
	}
	return (count == 4 ? 1 : 0);
}

int	is_validfile(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (-1);
	}
	return (fd);
}

int	is_validlines(int fd)
{
	char	*line;
	char	*tab[4];
	int		n;
	int		out;
	int		chunk;

	n = -1;
	out = 0;
	chunk = 0;
	while ((out = ft_get_next_line(fd, &line)) > 0)
	{
		chunk++;
		if ((!check_line(line, 4) && chunk % 5) || chunk > MAX_SIZE
			|| (!check_line(line, 0) && !(chunk % 5)))
			return (prompt_error());
		if (chunk % 5 && (++n || 1))
			tab[n % 4] = line;
		else if (!check_piece(tab))
			return (prompt_error());
	}
	close(fd);
	if (!check_piece(tab))
		return (prompt_error());
	return (1);
}
