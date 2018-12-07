/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:22:02 by kibotrel          #+#    #+#             */
/*   Updated: 2018/12/07 14:32:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				prompt_error(void)
{
	write(1, "error\n", 6);
	return (1);
}

static int		power(int val, int pow)
{
	long		ret;

	ret = val;
	if (pow == 0)
		return (1);
	if ((ret *= power(val, pow - 1)) > 2147483647)
		return (0);
	return (ret);
}

static int		num_len(int nb)
{
	int			i;

	i = 1;
	while ((nb / 10) > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

long double		ft_sqrt(long double nb)
{
	int			i;
	long double	a;

	i = 0;
	if (nb < 0.0)
		return (-1);
	if (nb == 0.0 || nb == 1.0)
		return (nb);
	if (nb > 7447441.0)
		return (2.0 * ft_sqrt(nb / 4.0));
	a = (float)power(10, num_len((int)nb) / 2.0);
	while (++i < 20)
		a = 0.5 * (a + (nb / a));
	return (a);
}
