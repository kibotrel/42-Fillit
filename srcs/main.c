/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:09:56 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/28 21:38:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

int	main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		if ((fd = is_validfile(av[1])) == -1 || !is_validlines(fd))
			return (1);
	}
	else
		ft_putendl("usage : ./fillit file");
	return (0);
}
