/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:18:44 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/08 15:25:11 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void	find_pb(t_vertex **mat, t_segment *sgt)
// {
// 	if (sgt->ya > 0)
// 		sgt->yb = sgt->ya;
// 	if (sgt->xa > 0)
// 		sgt->xb = sgt->xb - 1;
// }

// void	print_segment(t_segment segment, t_window wdw)
// {
// 	size_t	pxa;
// 	size_t	pxb;

// 	pxa = segment.xa;
// 	pya = segment.xb;
// 	if (segment.line > 0)
// 	{
// 		while (pxa > segment.xb)
// 		{
// 			mlx_pixel_put(wdw.mlx_ptr, wdw.win_ptr, pxa, segment.ya, 0xFFFFFF);
// 			--pxa;
// 		}
// 	}
// 	if (segment.col > 0)
// 	{
// 		while (pya > segment.yb)
// 		{
// 			mlx_pixel_put(wdw.mlx_ptr, wdw.win_ptr, segment.xa, pya, 0xFFFFFF);
// 			--pya;
// 		}
// 	}
// }

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

static int	shut_window(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free_matrix_vertex(window);
	exit(0);
}

static int	key_events(int keycode, t_window *window)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		shut_window(window);
	zoom(keycode, window);
	return (1);
}

static void	fill_map(t_vertex **matrix, size_t nb_line, size_t nb_col,
				t_window *window)
{
	window->map.matrix = matrix;
	window->map.nb_cols = nb_col;
	window->map.nb_line = nb_line;
}

 void	test_hook_key(t_window	*window)
 {
 	mlx_key_hook(window->win_ptr, key_events, window);
 	mlx_hook(window->win_ptr, 17, 0L, shut_window, window);
 }

void	print_matrix(t_vertex **matrix, size_t nb_line, size_t nb_col)
{
	size_t				y;
	struct s_window		window;

	y = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 800, 800, "fdf");
	fill_map(matrix, nb_line, nb_col, &window);
	while (y < nb_line)
	{
		print_vertex_mtvtx(matrix[y], window, nb_col);
		++y;
	}
	mlx_key_hook(window.win_ptr, key_events, &window);
	mlx_hook(window.win_ptr, 17, 0L, shut_window, &window);
	test_hook_key(&window);
	mlx_loop(window.mlx_ptr);
}
