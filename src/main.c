/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:26:06 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:26:09 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_file		*file;
	t_list		*figures_list;
	t_list		*list_start;
	t_map		*mapa;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file \n");
		return (0);
	}
	file = give_file_buff(argv[1]);
	if (checker(file))
	{
		figures_list = extract_figures(file);
		list_start = figures_list;
		if (!cut_find_chek(list_start, file->fig_num))
			return (0);
		mapa = solve(list_start, file->fig_num);
		print_map(mapa);
		free_map(mapa);
	}
	return (0);
}
