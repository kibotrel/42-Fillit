/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 00:35:00 by kibotrel          #+#    #+#             */
/*   Updated: 2018/12/07 14:17:29 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_corners(char tab[4][4], int x, int y, int corner)
{
	if (corner == 0)
		return (tab[x][y + 1] == '#' && tab[x + 1][y] == '#');
	if (corner == 1)
		return (tab[x][y - 1] == '#' && tab[x + 1][y] == '#');
	if (corner == 2)
		return (tab[x - 1][y] == '#' && tab[x][y + 1] == '#');
	return (tab[x][y - 1] == '#' && tab[x - 1][y] == '#');
}

static int	check_tb(char tab[4][4], int x, int y, int side)
{
	int	result;

	result = 0;
	if (side == 0)
	{
		if (tab[x][y + 1] == '#' && tab[x][y - 1] == '#')
			result++;
		if (tab[x + 1][y] == '#' && tab[x][y + 1] == '#')
			result++;
		if (tab[x + 1][y] == '#' && tab[x][y - 1] == '#')
			result++;
	}
	if (side == 1)
	{
		if (tab[x][y - 1] == '#' && tab[x][y + 1] == '#')
			result++;
		if (tab[x - 1][y] == '#' && tab[x][y + 1] == '#')
			result++;
		if (tab[x - 1][y] == '#' && tab[x][y - 1] == '#')
			result++;
	}
	return (result);
}

static int	check_lr(char tab[4][4], int x, int y, int side)
{
	int	result;

	result = 0;
	if (side == 0)
	{
		if (tab[x][y + 1] == '#' && tab[x - 1][y] == '#')
			result++;
		if (tab[x + 1][y] == '#' && tab[x][y + 1] == '#')
			result++;
		if (tab[x + 1][y] == '#' && tab[x - 1][y] == '#')
			result++;
	}
	if (side == 1)
	{
		if (tab[x - 1][y] == '#' && tab[x + 1][y] == '#')
			result++;
		if (tab[x - 1][y] == '#' && tab[x][y - 1] == '#')
			result++;
		if (tab[x + 1][y] == '#' && tab[x][y - 1] == '#')
			result++;
	}
	return (result);
}

static int	check_inner(char tab[4][4], int x, int y)
{
	int	result;

	result = check_corners(tab, x, y, 0) + check_corners(tab, x, y, 1)
		+ check_corners(tab, x, y, 2) + check_corners(tab, x, y, 3);
	if (tab[x - 1][y] == '#' && tab[x + 1][y] == '#')
		result++;
	if (tab[x][y - 1] == '#' && tab[x][y + 1] == '#')
		result++;
	return (result);
}

int			check_grid(char tab[4][4], int x, int y)
{
	int neighbor;

	neighbor = 0;
	if (x == 0 && y == 0)
		neighbor += check_corners(tab, x, y, 0);
	else if (x == 0 && y < 3)
		neighbor += check_tb(tab, x, y, 0);
	else if (x == 0 && y == 3)
		neighbor += check_corners(tab, x, y, 1);
	else if (x < 3 && y == 0)
		neighbor += check_lr(tab, x, y, 0);
	else if (x < 3 && y < 3)
		neighbor += check_inner(tab, x, y);
	else if (x < 3 && y == 3)
		neighbor += check_lr(tab, x, y, 1);
	else if (x == 3 && y == 0)
		neighbor += check_corners(tab, x, y, 2);
	else if (x == 3 && y < 3)
		neighbor += check_tb(tab, x, y, 1);
	else if (x == 3 && y == 3)
		neighbor += check_corners(tab, x, y, 3);
	return (neighbor);
}
