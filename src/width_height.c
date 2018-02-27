/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:51 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:52 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			find_height(t_figure *figure)
{
	int i;
	int j;

	figure->h = 1;
	i = -1;
	while (++i < FIELD_SIZE)
	{
		j = 0;
		while (j < FIELD_SIZE)
		{
			if (figure->data[i][j] == '#')
			{
				figure->h = i + 1;
			}
			j++;
		}
	}
}

void			find_widtht(t_figure *figure)
{
	int i;
	int j;

	figure->w = 1;
	i = -1;
	while (++i < FIELD_SIZE)
	{
		j = -1;
		while (++j < FIELD_SIZE)
		{
			if (figure->data[i][j] == '#')
			{
				if (figure->w <= j + 1)
					figure->w = j + 1;
			}
		}
	}
}

t_figure		*find_figure_size(t_figure *figure)
{
	find_widtht(figure);
	find_height(figure);
	return (figure);
}
