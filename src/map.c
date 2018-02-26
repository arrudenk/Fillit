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

void		free_map(m_map *map)
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

void		print_map(m_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->field[i]);
		ft_putchar('\n');
	}
}

m_map		*new_map(int size)
{
	m_map	*map;
	int		i;
	int		j;

	map = (m_map *)ft_memalloc(sizeof(m_map));
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

int			place(f_figure *figure, m_map *map, int x, int y)
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

void		set_piece(f_figure *figure, m_map *map, t_coord *coord, char c)
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
