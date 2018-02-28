/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 12:25:57 by arrudenk          #+#    #+#             */
/*   Updated: 2018/02/23 12:25:58 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H

# define FIELD_SIZE 4
# include <libft.h>

typedef struct	s_figure
{
	char		data[FIELD_SIZE][FIELD_SIZE];
	char		alphabet;
	int			w;
	int			h;
}				t_figure;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_map
{
	char		**field;
	int			size;
}				t_map;

typedef struct	s_file
{
	char		*buff;
	int			size;
	int			fig_num;
}				t_file;

int				check_cols(char *argv);
t_file			*give_file_buff(char *argv);
int				cut_find_chek(t_list *list, int fig_num);
void			ft_lstrev(t_list **begin_list);
t_figure		*init_figures_field(void);
t_figure		*cut(t_figure *field);
t_list			*extract_figures(t_file *file);
void			set_minus_one(int *c, int *a);
int				checker(t_file *file);
int				check_figure(t_figure *figure);
int				pairing_func(const int *rows, const int *cols, int k1, int k2);
void			free_map(t_map *map);
t_map			*new_map(int size);
void			print_map(t_map *map);
int				place(t_figure *figure, t_map *map, int x, int y);
void			set_piece(t_figure *figure, t_map *map,
				t_coord *coord, char c);
t_map			*solve(t_list *figure_list, int figures_number);
t_figure		*find_figure_size(t_figure *figure);
t_coord			*coord_new(int x, int y);

#endif
