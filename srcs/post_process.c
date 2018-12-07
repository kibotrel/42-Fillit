/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:41:14 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/07 14:29:17 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char			ft_freturn(void *ptr, char ret)
{
	free(ptr);
	return (ret);
}

static char		*create_map(const int size)
{
	int			y;
	int			len;
	char		*ret;

	y = -1;
	len = ((size + 1) * size);
	if (!(ret = malloc(sizeof(char) * len)))
		return (NULL);
	while (++y < len)
		ret[y] = '.';
	y = size;
	while (--y >= 0)
		ret[size + (y * (size + 1))] = '\n';
	return (ret);
}

char			render_map(t_map *map, t_piece *p, const int j)
{
	t_vec2		cpos;
	t_vec2		pos;

	p->val = p->ref;
	if (!map->res && !(map->res = create_map(map->size)))
		return (-1);
	pos.y = -1;
	while (++pos.y < p->h)
	{
		pos.x = -1;
		cpos.y = p->y + pos.y;
		while (++pos.x < p->w)
			if ((p->val >> ((16 * pos.y) + (16 - p->w) + pos.x)) & 1)
			{
				cpos.x = p->x + (p->w - (pos.x + 1));
				map->res[cpos.x + cpos.y * (map->size + 1)] = 'A' + j;
			}
	}
	return (1);
}
