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
# include "libft.h"

typedef struct s_figure
{
	char	data[FIELD_SIZE][FIELD_SIZE];
	char	alphabet;
	int		w;
	int		h;
}			f_figure;
typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;
typedef struct s_map
{
	char	**field;
	int		size;
}			m_map;
typedef struct s_file
{
	char	*buff;
	int		size;
	int		fig_num;
}			t_file;
t_file			*give_file_buff(char *argv);
int				cut_find_chek(t_list *list, int fig_num);
void			ft_lstrev(t_list **begin_list);
f_figure		*init_figures_field(void);
void			print_figures(f_figure *field);
f_figure		*cut(f_figure *field);
t_list			*create_figures_list(char **columns, int figures_number);
t_list			*extract_figures(t_file *file);
void			set_minus_one(int *c, int *a);
int				checker(t_file *file);
int				check4x4(t_file *file);
int				syntax_ceck(t_file *file);
int				wrong_symbol(char c);
int				check_figure(f_figure *figure);
int				control_sum(f_figure *figure);
int				pairing_func(const int *rows, const int *cols, int k1, int k2);
void			free_map(m_map *map);
m_map			*new_map(int size);
void			print_map(m_map *map);
int				place(f_figure *figure, m_map *map, int x, int y);
void			set_piece(f_figure *figure, m_map *map,
				t_coord *coord, char c);
m_map			*solve(t_list *figure_list, int figures_number);
void			*find_figure_size(f_figure *figure);
void			find_widtht(f_figure *figure);
void			find_height(f_figure *figure);
int				get_x_shift(f_figure *field);
int				get_y_shift(f_figure *field);
f_figure		*move_by_y(f_figure *field, char fig);
f_figure		*move_by_x(f_figure *field, char fig);
t_coord			*coord_new(int x, int y);

#endif //FILLIT_HEADER_H
