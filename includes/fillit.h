/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:13:51 by kibotrel          #+#    #+#             */
/*   Updated: 2018/11/28 14:29:57 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_SIZE 129

int	prompt_error(void);
int	check_line(char *line, size_t n);
int	is_validfile(char *file);
int	is_validlines(int fd);

#endif
