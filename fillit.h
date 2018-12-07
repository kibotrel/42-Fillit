/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:00:19 by kibotrel          #+#    #+#             */
/*   Updated: 2018/12/07 14:10:24 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_PIECE 26
# define MAX_SIZE 16
# define MASK 0b1000000000000000100000000000000010000000000000001000000000000000

typedef unsigned short	t_int16;
typedef unsigned long	t_int64;

typedef struct			s_vec2
{
	short int	x : 8;
	short int	y : 8;
}						t_vec2;

typedef struct			s_piece
{
	t_int64		val;
	t_int64		ref;
	short int	x : 8;
	short int	y : 8;
	short int	w : 8;
	short int	h : 8;
}						t_piece;

typedef struct			s_map
{
	t_int16		map[16];
	t_piece		pieces[26];
	short int	piece_count : 8;
	short int	size : 8;
	char		*res;
}						t_map;

/*
**	utils.c
*/

int						prompt_error(void);
long double				ft_sqrt(long double nb);

/*
**	check_grid.c
*/

int						check_grid(char tab[4][4], int x, int y);

/*
**	parsing.c
*/

int						is_validfile(int fd, t_map *map);

/*
**	post_parse.c
*/

t_piece					*reset_piece(t_piece *piece);
t_piece					convert_piece(const char tab[4][4]);

/*
**	process.c
*/

char					process(t_map *map);

/*
**	post_process.c
*/

char					ft_freturn(void *ptr, char ret);
char					render_map(t_map *map, t_piece *p, const int j);

#endif
