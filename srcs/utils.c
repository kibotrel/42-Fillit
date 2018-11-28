/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:22:02 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/28 15:25:59 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	prompt_error(void)
{
	ft_putendl("error");
	return (0);
}

int	check_line(char *line, size_t n)
{
	return ((ft_strlen(line) == n) ? 1 : 0);
}
