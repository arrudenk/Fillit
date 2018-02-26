/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:29 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:30 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pairing_func(const int *rows, const int *cols ,int k1, int k2)
{
	int i;

	i = -1;
	while (++i < FIELD_SIZE)
	{
		k1 = 10 * k1 + rows[i];
		k2 = 10 * k2 + cols[i];
	}
	return ((((k1 + k2) * (k1 + k2 + 1)) / 2) + k2);
}

int		control_sum(f_figure *figure)
{
	int			*rows;
	int			*cols;
	t_coord		*a_b;
	t_coord		*row_col;

	rows = ft_memalloc(sizeof(int) * FIELD_SIZE);
	cols = ft_memalloc(sizeof(int) * FIELD_SIZE);
	a_b = coord_new(-1, -1);
	row_col = coord_new(0, 0);
	while (++a_b->x < FIELD_SIZE)
	{
		a_b->y = -1;
		while (++a_b->y < FIELD_SIZE)
		{
			rows[a_b->y] += (figure->data[a_b->x][a_b->y] == '#') ? 1 : 0;
			cols[a_b->x] += (figure->data[a_b->x][a_b->y] == '#') ? 1 : 0;
		}
	}
	return (pairing_func(rows,cols,row_col->x, row_col->y));
}

int		check_figure(f_figure *figure)
{
	int sum;

	sum = control_sum(figure);
	if (sum == 8907430 || sum == 2930530 || sum == 5817865 || sum == 13576765
		|| sum == 5817055 || sum == 2930710 || sum == 8909410
		|| sum == 13577755 || sum == 13064827 || sum == 13067716
		|| sum == 5817955 || sum == 5816965 || sum == 9684400
		|| sum == 3152605 || sum == 9293305
		|| sum == 9291415 || sum == 3152515)
		return (1);
	else
		return (0);
}
