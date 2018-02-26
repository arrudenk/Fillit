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

int			main(int argc, char **argv)
{
	(void)argc;
	t_file	*file;

	file = give_file_buff(argv[1]);
	if (checker(file))
	{
		t_list		*figures_list = extract_figures(file);
		t_list		*temp;
		m_map		*mapa;

		temp = figures_list->next;
		if(!cut_find_chek(temp, file->fig_num))
			return (0);
		mapa = solve(figures_list->next, file->fig_num);
		print_map(mapa);
		free_map(mapa);
	}
	return (0);
}
