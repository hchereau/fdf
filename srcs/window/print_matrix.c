/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:18:44 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/25 11:01:00 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_vertex_mtvtx(t_vertex *mat, t_window wdw, size_t col)
{
	size_t		x;
	t_vertex	vertex;

	x = 0;
	while (x < col)
	{
		vertex = mat[x];
		mlx_pixel_put(wdw.mlx_ptr, wdw.win_ptr,
			vertex.x, vertex.y, vertex.color);
		++x;
	}
}

static void	fill_map(t_vertex **matrix, size_t nb_line, size_t nb_col,
				t_window *window)
{
	window->map.matrix = matrix;
	window->map.nb_cols = nb_col;
	window->map.nb_line = nb_line;
}

void	print_matrix(t_vertex **cp_matrix, size_t nb_line, size_t nb_col,
		t_vertex **matrix)
{
	size_t				y;
	struct s_window		window;

	y = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WIDTH, HEIGHT, "fdf");
	window.img.ptr_img = mlx_new_image(window.mlx_ptr, WIDTH, HEIGHT);
	if (window.img.ptr_img == NULL)
	{
		free(window.mlx_ptr);
		free(window.win_ptr);
		return ;
	}
	window.map.zoom = 0;
	fill_map(matrix, nb_line, nb_col, &window);
	window.map.cp_matrix = cp_matrix;
	window.img.addr = mlx_get_data_addr(window.img.ptr_img, &window.img.bpp,
					&window.img.size_line, &window.img.endian);
	while (y < nb_line)
	{
		print_vertex_mtvtx(window.map.cp_matrix[y], window, nb_col);
		++y;
	}
	test_hook_key(&window);
	mlx_loop(window.mlx_ptr);
}
