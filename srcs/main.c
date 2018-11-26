/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:09:56 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/26 19:43:26 by kibotrel         ###   ########.fr       */
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
	char	*line;
	int		fd;
	int		out;
	int		chunk;

	out = 0;
	chunk = 0;
	if (ac == 2)
	{
		if (!is_validfile(av[1]))
			return (1);
		while ((out = ft_get_next_line(fd, &line)) > 0)
		{
			chunk++;
			if ((!check_line(line, 4) && (chunk % 5)) || ((!check_line(line, 0) && !(chunk % 5)) || chunk > MAX_SIZE))
			{	
				ft_putendl("error");
				free(line);
				return (1);
			}
			ft_putendl(line);
			free(line);
		}
		if (fd > 2)
			close(fd);
	}
	else	
		ft_putendl("usage : ./fillit file");
	return (0);
}
