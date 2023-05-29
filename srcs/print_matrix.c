/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:18:44 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/30 01:47:55 by hchereau         ###   ########.fr       */
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

void	print_matrix(t_vertex **matrix, size_t nb_line, size_t nb_col)
{
	size_t				y;
	struct s_window		window;

	y = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 800, 800, "fdf");
	while (y < nb_line)
	{
		print_vertex_mtvtx(matrix[y], window, nb_col);
		++y;
	}
	mlx_loop(window.mlx_ptr);
}
