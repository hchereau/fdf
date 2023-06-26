/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:03:02 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/26 09:10:56 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_coord_vertex(t_vertex *vertex, size_t i, size_t index_line,
			char **vertex_point)
{
	vertex->x = DISTANCE * i;
	vertex->y = DISTANCE * index_line;
	vertex->z = ft_atoi(vertex_point[0]);
}

static void	fill_color_vertex(t_vertex *vertex, char **vertex_point)
{
	if (vertex_point[1] != NULL)
		vertex->color = base_convert(vertex_point[1], BASE_HEXA);
	else
		vertex->color = 0xFFFFFFF;
}

static void	add_vertex(size_t i, char *s, t_vertex **matrix,
	size_t index_line)
{
	char	**vertex_point;

	vertex_point = ft_split(s, ',');
	fill_coord_vertex(&matrix[index_line][i], i, index_line, vertex_point);
	fill_color_vertex(&matrix[index_line][i], vertex_point);
	free_split(vertex_point);
}

void	fill_matrix_line(t_vertex **matrix, char ***matrix_char,
		size_t index_line, size_t nb_cols)
{
	size_t	i;

	matrix[index_line] = (t_vertex *)malloc(nb_cols * sizeof(t_vertex));
	if (matrix[index_line] == NULL)
		return ;
	i = 0;
	while (i < nb_cols)
	{
		add_vertex(i, matrix_char[index_line][i], matrix, index_line);
		++i;
	}
}
