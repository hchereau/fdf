/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/19 11:01:49 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"
# include <math.h>
# include "mlx.h"

# define WHITESPACE	" \t\n"
# define DISTANCE	10
# define BASE_HEXA	"0123456789ABCDEF"
# define CROSS		17
# define ECHAP		53
# define ZOOM		1

typedef struct s_vertex {
	size_t	y;
	size_t	x;
	size_t	z;
	size_t	color;
}	t_vertex;

typedef struct s_segment {
	size_t	xa;
	size_t	ya;
	size_t	za;
	size_t	xb;
	size_t	yb;
	size_t	zb;
	size_t	line;
	size_t	col;
}	t_segment;

typedef struct s_map{
	t_vertex	**matrix;
	t_vertex	**cp_matrix;
	size_t		nb_line;
	size_t		nb_cols;
	size_t		zoom;
}	t_map;

typedef struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_window;

size_t		get_nb_line(int fd);
char		***create_char_matrix(int fd, size_t nb_line);
char		**ft_csplit(const char *s, char *charset);
void		free_strs(char **strs);
size_t		ft_strlen_mat(char **matrix);
t_vertex	**create_vertex_matrix(size_t nb_line, char ***matrix_char);
int			base_convert(char *convert, char *base);
void		test_hook_key(t_window	*window);
int			key_events(int keycode, t_window *window);
int			shut_window(t_window *window);
void		print_matrix(t_vertex **cp_matrix, size_t nb_line, size_t nb_col,
				t_vertex **matrix);
bool		is_valid_matrix(char ***matrix, size_t nb_line);
size_t		count_point_on_line(char ***matrix);
void		zoom(int keycode, t_window *window);
void		fill_matrix_line(t_vertex **matrix, char ***matrix_char,
				size_t index_line, size_t nb_cols);
t_vertex	**cp_matrix_vertex(t_vertex **matrix, size_t nb_line,
				size_t nb_cols);
t_vertex	**malloc_matrix(size_t nb_line, size_t nb_cols);
void		free_matrix_char(char ***matrix_char);
void		free_matrix_vertex(t_window *window);
void		free_split(char **split);
#endif
