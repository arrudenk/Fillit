/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:17 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:19 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		free_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
	{
		ft_memdel((void *)&(map->field[i]));
	}
	ft_memdel((void *)&(map->field));
	ft_memdel((void *)&map);
}

void		print_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->field[i]);
		ft_putchar('\n');
	}
}

t_map		*new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	i = -1;
	map->field = (char **)ft_memalloc(sizeof(char *) * size);
	while (++i < size)
	{
		map->field[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
		{
			map->field[i][j] = '.';
		}
	}
	return (map);
}

int			place(t_figure *figure, t_map *map, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < figure->w)
	{
		j = -1;
		while (++j < figure->h)
		{
			if (figure->data[j][i] == '#' && map->field[y + j][x + i] != '.')
				return (0);
		}
	}
	set_piece(figure, map, coord_new(x, y), figure->alphabet);
	return (1);
}

void		set_piece(t_figure *figure, t_map *map, t_coord *coord, char c)
{
	int i;
	int j;

	set_minus_one(&i, &j);
	while (++i < figure->w)
	{
		j = -1;
		while (++j < figure->h)
		{
			if (figure->data[j][i] != '.')
				map->field[coord->y + j][coord->x + i] = c;
		}
	}
	ft_memdel((void *)&coord);
}
