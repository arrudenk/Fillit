/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:11 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:12 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

f_figure		*init_figures_field(void)
{
	f_figure		*f;
	unsigned int	x;
	unsigned int	y;

	f = malloc(sizeof(f_figure));
	x = 0;
	y = 0;
	while (x < FIELD_SIZE)
	{
		while (y < FIELD_SIZE)
		{
			f->data[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (f);
}

void			print_figures(f_figure *field)
{
	int x;
	int y;

	x = -1;
	while (++x < field->h)
	{
		y = -1;
		while (++y < field->w)
		{
			if (field->data[x][y] == '.')
				ft_putchar(' ');
			else
				ft_putchar(field->data[x][y]);
		}
		ft_putstr("\n");
	}
	ft_putstr("\n");
}
