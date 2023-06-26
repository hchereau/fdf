/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:18:44 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/26 11:06:53 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	print_vertex_mtvtx(t_vertex *mat, t_window wdw, size_t col)
{
	size_t		x;
	t_vertex	vertex;

	x = 0;
	while (x < col)
	{
		vertex = mat[x];
		my_mlx_pixel_put(&wdw.img, vertex.x, vertex.y, vertex.color);
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

static	int	fill_window(t_window *window, t_vertex **cp_matrix)
{
	int		res;

	res = 1;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "fdf");
	window->img.ptr_img = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	if (window->img.ptr_img == NULL)
	{
		free(window->mlx_ptr);
		free(window->win_ptr);
		res = 0;
	}
	else
	{
		window->map.zoom = 0;
		window->map.cp_matrix = cp_matrix;
		window->img.addr = mlx_get_data_addr(window->img.ptr_img,
				&window->img.bpp, &window->img.size_line, &window->img.endian);

	}
	return (res);
}

void	print_matrix(t_vertex **cp_matrix, size_t nb_line, size_t nb_col,
		t_vertex **matrix)
{
	size_t				y;
	struct s_window		window;

	y = 0;
	if (fill_window(&window, cp_matrix))
	{
		fill_map(matrix, nb_line, nb_col, &window);
		while (y < nb_line)
		{
			print_vertex_mtvtx(window.map.cp_matrix[y], window, nb_col);
			++y;
		}
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.img.ptr_img, 0, 0);
		test_hook_key(&window);
		mlx_loop(window.mlx_ptr);
	}
}
