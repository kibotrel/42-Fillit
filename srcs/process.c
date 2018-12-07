/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:49:57 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/07 14:27:18 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static void		optimize_future(t_map *map, t_piece *pieces, int j)
{
	int			i;
	t_piece		current;

	i = 1;
	current = *pieces;
	while (i + j < map->piece_count && pieces[i].ref != current.ref)
		i++;
	if (i + j == map->piece_count || pieces[i].ref != current.ref)
		return ;
	pieces[i].x = -1;
	pieces[i].y = current.y;
	pieces[i].val = current.ref;
	if (current.x + (current.w - 1) < map->size - (current.w - 1))
	{
		pieces[i].y--;
		pieces[i].x = current.x + (current.w - 1) - 1;
		pieces[i].val = current.val >> (current.w - 1);
	}
}

static char		btrk(t_map *map, const int size, const int j)
{
	t_int64		*frag;

	while (++map->pieces[j].y < size - (map->pieces[j].h - 1))
	{
		frag = (t_int64 *)&(map->map[map->pieces[j].y]);
		while (++map->pieces[j].x < size - (map->pieces[j].w - 1))
		{
			if ((*frag & map->pieces[j].val) == 0)
			{
				*frag ^= map->pieces[j].val;
				optimize_future(map, &map->pieces[j], j);
				if (j + 1 >= map->piece_count || btrk(map, size, j + 1))
					return (render_map(map, &map->pieces[j], j));
				reset_piece(&map->pieces[j + 1]);
				*frag ^= map->pieces[j].val;
			}
			map->pieces[j].val >>= 1;
		}
		map->pieces[j].val = map->pieces[j].ref;
		map->pieces[j].x = -1;
	}
	return (0);
}

static int		get_map_size(const int piece_count)
{
	int			ret;
	double		root;

	root = ft_sqrt(piece_count * 4);
	ret = (int)root;
	if ((root - (double)ret) == 0)
		ret--;
	return (ret);
}

char			process(t_map *map)
{
	int			i;
	char		lp;

	i = 0;
	lp = 0;
	map->res = NULL;
	map->size = get_map_size(map->piece_count);
	while (i < 16)
		map->map[i++] = 0;
	while (lp == 0 && map->size < MAX_SIZE)
	{
		i = 0;
		while (i < map->piece_count)
			reset_piece(&map->pieces[i++]);
		lp = btrk(map, ++map->size, 0);
	}
	if (lp < 0 || map->size >= MAX_SIZE)
		return (ft_freturn(map->res, 1));
	write(1, map->res, (map->size + 1) * map->size);
	free(map->res);
	return (0);
}

int				main(int ac, char *const *av)
{
	int			fd;
	t_map		map;

	if (ac != 2)
		return (0 * write(1, "usage: ./fillit file\n", 21));
	if ((fd = open(av[1], O_RDONLY)) >= 0 && !is_validfile(fd, &map))
		return (process(&map));
	return (prompt_error());
}
