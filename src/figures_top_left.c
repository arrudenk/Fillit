/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_top_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:25 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:27 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				get_x_shift(t_figure *field)
{
	int x;
	int y;
	int x_shift;

	x_shift = 0;
	set_minus_one(&x, &y);
	while (++x < 4)
	{
		while (++y < 4)
		{
			if (field->data[x][y] != '.')
			{
				x_shift = x;
				return (x_shift);
			}
		}
		y = -1;
	}
	return (x_shift);
}

int				get_y_shift(t_figure *field)
{
	int x;
	int y;
	int y_shift;

	y_shift = 3;
	x = -1;
	y = 4;
	while (++x < 4)
	{
		while (--y > -1)
		{
			if (field->data[x][y] != '.')
			{
				if (y_shift > y)
				{
					y_shift = y;
				}
			}
		}
		y = 4;
	}
	return (y_shift);
}

t_figure		*move_by_y(t_figure *field)
{
	int x;
	int y;
	int shift_y;

	shift_y = get_y_shift(field);
	set_minus_one(&x, &y);
	if (shift_y > 0)
	{
		while (++x < 4)
		{
			while (++y < 4)
				if (field->data[x][y] != '.')
				{
					field->data[x][y - shift_y] = '#';
					field->data[x][y] = '.';
				}
			y = -1;
		}
	}
	return (field);
}

t_figure		*move_by_x(t_figure *field)
{
	int x;
	int y;
	int shift_x;

	shift_x = get_x_shift(field);
	set_minus_one(&x, &y);
	if (shift_x > 0)
	{
		while (++x < 4)
		{
			while (++y < 4)
				if (field->data[x][y] != '.')
				{
					field->data[x - shift_x][y] = '#';
					field->data[x][y] = '.';
				}
			y = -1;
		}
	}
	return (field);
}

t_figure		*cut(t_figure *field)
{
	static char fig = 65;

	field = move_by_x(field);
	field = move_by_y(field);
	field->alphabet = fig;
	fig++;
	return (field);
}
