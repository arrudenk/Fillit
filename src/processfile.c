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

#include <fcntl.h>
#include "header.h"

int		check_figure_field(char *two_one)
{
	int i;

	i = -1;
	while (two_one[++i])
	{
		if (i != 19)
		{
			if (two_one[i] == '\n' && two_one[i + 1] == '\n')
				return (0);
		}
	}
	return (1);
}

int		check_cols(char *argv)
{
	char	*buff;
	int		fd;

	buff = ft_strnew(21);
	fd = open(argv, O_RDONLY);
	while (read(fd, (void *)buff, 21) > 0)
	{
		if (!check_figure_field(buff))
		{
			ft_putstr("error");
			return (0);
		}
	}
	close(fd);
	return (1);
}

t_list		*create_figures_list(char **columns)
{
	t_coord			*x_i;
	t_coord			*c_a;
	t_list			*figures_list;
	t_figure		*temp;

	c_a = coord_new(-1, -1);
	x_i = coord_new(0, 0);
	temp = init_figures_field();
	figures_list = NULL;
	while (columns[x_i->y])
	{
		set_minus_one(&c_a->x, &c_a->y);
		while (columns[x_i->y][++c_a->y])
			temp->data[x_i->x][++c_a->x] = columns[x_i->y][c_a->y];
		x_i->x++;
		if (++x_i->y % FIELD_SIZE == 0)
		{
			ft_lstadd(&figures_list, ft_lstnew(temp, sizeof(t_figure)));
			ft_memdel((void **)&temp);
			temp = init_figures_field();
			x_i->x = 0;
		}
	}
	ft_lstrev(&figures_list);
	return (figures_list);
}

t_list		*extract_figures(t_file *file)
{
	char		**columns;
	t_list		*figurelist;
	int			i;

	i = -1;
	columns = ft_strsplit(file->buff, '\n');
	figurelist = create_figures_list(columns);
	while (columns[++i])
		ft_strdel(&columns[i]);
	free(columns);
	return (figurelist);
}
