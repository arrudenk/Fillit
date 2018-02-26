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
	t_list		*temp;
	t_map		*mapa;

	if (argc != 2)
	{
		ft_putstr("error: arguments \n");
		return (0);
	}
	file = give_file_buff(argv[1]);
	if (checker(file))
	{
		figures_list = extract_figures(file);
		temp = figures_list->next;
		if (!cut_find_chek(temp, file->fig_num))
			return (0);
		mapa = solve(figures_list->next, file->fig_num);
		print_map(mapa);
		free_map(mapa);
	}
	return (0);
}
