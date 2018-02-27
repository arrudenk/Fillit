/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileChecker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:41 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		wrong_symbol(char c)
{
	if (c != '.' && c != '#' && c != '\n' && c != '\0')
		return (1);
	else
		return (0);
}

int		syntax_ceck(t_file *file)
{
	int i;
	int newline;
	int valid_new_lines_score;

	valid_new_lines_score = (file->size / 21 * 4 + (file->size / 21)) - 1;
	i = -1;
	newline = 0;
	while (file->buff[++i] != '\0')
	{
		if (file->buff[i] == '\n')
			newline++;
		if (wrong_symbol(file->buff[i]))
			return (0);
	}
	if (newline != valid_new_lines_score)
		return (0);
	return (1);
}

int		check4x4(t_file *file)
{
	t_coord	*x_y;
	char	**column;

	x_y = coord_new(-1, -1);
	column = ft_strsplit(file->buff, '\n');
	while (column[++x_y->x + 1])
	{
		x_y->y = -1;
		while (column[x_y->x][++x_y->y])
		{
		}
		if (x_y->y != 4)
		{
			while (*column)
				ft_strdel(&*column++);
			return (0);
		}
	}
	while (*column)
		ft_strdel(&*column++);
	ft_memdel((void **)column);
	return (x_y->x < 3 ? 0 : 1);
}

int		checker(t_file *file)
{
	int		first_check;
	int		second_check;

	if (file->size < 19)
		return (0);
	first_check = syntax_ceck(file);
	second_check = check4x4(file);
	if (first_check == 1 && second_check == 1)
		return (1);
	else
	{
		ft_putstr("usage : ./fillit error \n");
		return (0);
	}
}
