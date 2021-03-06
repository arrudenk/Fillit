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

t_figure		*init_figures_field(void)
{
	t_figure		*f;
	unsigned int	x;
	unsigned int	y;

	f = malloc(sizeof(t_figure));
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
