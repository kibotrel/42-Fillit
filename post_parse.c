/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:36:47 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/07 14:23:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_int64		up_left(t_int64 piece_val)
{
	if (piece_val == 0)
		return (piece_val);
	while ((piece_val & 0b1111111111111111) == 0)
		piece_val >>= 16;
	while ((piece_val & MASK) == 0)
		piece_val <<= 1;
	return (piece_val);
}

t_piece				*reset_piece(t_piece *piece)
{
	if (piece)
	{
		piece->val = piece->ref;
		piece->x = -1;
		piece->y = -1;
	}
	return (piece);
}

t_piece				convert_piece(const char tab[4][4])
{
	unsigned int	i;
	t_vec2			pos;
	t_piece			ret;

	i = 0;
	pos.y = 4;
	while (i < sizeof(ret))
		((char *)(&ret))[i++] = 0;
	while (--pos.y >= 0)
	{
		pos.x = -1;
		while (++pos.x < 4 && ((ret.val <<= 1) || 1))
			if (tab[pos.y][pos.x] == '#')
				ret.val |= 1;
		ret.val <<= (16 - 4);
	}
	ret.ref = up_left(ret.val);
	ret.val = ret.ref;
	while ((ret.ref & (MASK >> ret.w)) != 0)
		ret.w++;
	while (ret.h < 4 && ret.ref >> (ret.h * 16) != 0)
		ret.h++;
	return (ret);
}
