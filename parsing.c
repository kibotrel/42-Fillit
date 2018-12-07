/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:01:24 by kibotrel          #+#    #+#             */
/*   Updated: 2018/12/07 14:20:40 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

static int	check_charset(char tab[4][4])
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
	return (count == 4);
}

static int	is_validpiece(char tab[4][4])
{
	int		neighbor;
	int		x;
	int		y;

	x = -1;
	neighbor = 0;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (tab[x][y] == '#')
				neighbor += check_grid(tab, x, y);
	}
	return (neighbor >= 2);
}

static int	is_validtab(int fd, char tab[4][4])
{
	char	buffer[5];
	int		out;
	int		n;
	int		i;

	out = 0;
	n = -1;
	while (++n < 4 && (out = read(fd, buffer, 5) == 5))
	{
		i = -1;
		if (!out || buffer[4] != '\n')
			return (0);
		while (++i < 4)
			tab[n][i] = buffer[i];
	}
	return (n == 4);
}

int			is_validfile(int fd, t_map *map)
{
	char	tab[4][4];
	char	buffer;
	int		out;
	int		piece;

	out = 0;
	piece = 0;
	while (!piece || (out = read(fd, &buffer, 1) > 0))
	{
		if (piece >= MAX_PIECE || (piece && buffer != '\n'))
			return (-1 + 0 * close(fd));
		if (!is_validtab(fd, tab) || !check_charset(tab) || !is_validpiece(tab))
			return (-1 + 0 + close(fd));
		map->pieces[piece] = convert_piece(tab);
		piece++;
	}
	map->piece_count = piece;
	return (0 * close(fd));
}
