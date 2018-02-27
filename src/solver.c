/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:42 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_figure	*tetri;

	if (list == NULL)
		return (1);
	y = -1;
	tetri = (t_figure *)(list->content);
	while (++y < map->size - tetri->h + 1)
	{
		x = -1;
		while (++x < map->size - tetri->w + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, coord_new(x, y), '.');
			}
		}
	}
	return (0);
}

int			hight_sqrt(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
	{
		size++;
	}
	return (size);
}

t_map		*solve(t_list *figure_list, int figures_number)
{
	t_map	*map;
	int		size;

	size = hight_sqrt(figures_number * 4);
	map = new_map(size);
	while (!solve_map(map, figure_list))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}
