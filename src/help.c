/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:21:34 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 13:21:35 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>


int		cut_find_chek(t_list *list, int fig_num)
{
	int i;

	i = -1;
	while (++i < fig_num)
	{
		cut(list->content);
		if (!check_figure(list->content))
		{
			ft_putstr("error: wrong tetramine \n");
			return (0);
		}
		find_figure_size(list->content);
		list = list->next;
	}
	return (1);
}

t_file		*give_file_buff(char *argv)
{
	t_file	*file;
	int		fd;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->size = 0;
	file->buff = ft_memalloc(sizeof(char) + 1);
	fd = open(argv, O_RDONLY);
	while (read(fd, (void *)file->buff, 1) > 0)
		file->size++;
	file->size++;
	close(fd);
	ft_memdel((void *)&file->buff);
	fd = open(argv, O_RDONLY);
	file->buff = ft_memalloc(sizeof(char) * file->size + 1);
	read(fd, file->buff, file->size);
	close(fd);
	file->fig_num = file->size / 20;
	return (file);
}

t_coord		*coord_new(int x, int y)
{
	t_coord		*coord;

	coord = ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

void	set_minus_one(int *c, int *a)
{
	*c = -1;
	*a = -1;
}

void	ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

