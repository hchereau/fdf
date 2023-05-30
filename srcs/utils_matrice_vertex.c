/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:02:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/30 15:12:33 by hchereau         ###   ########.fr       */
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
}

size_t	count_point_on_line(char ***matrix)
{
	size_t	nb_cols;

	nb_cols = 0;
	while (matrix[0][nb_cols] != NULL)
		++nb_cols;
	return (nb_cols);
}

t_vertex	**create_vertex_matrix(size_t nb_line, char ***matrix_char)
{
	struct s_vertex	**matrix;
	size_t			index_line;
	size_t			nb_cols;
	size_t			i;

	index_line = 0;
	nb_cols = count_point_on_line(matrix_char);
	matrix = (t_vertex **)malloc(nb_line * sizeof(t_vertex *));
	while ((index_line < nb_line) && matrix != NULL)
	{
		matrix[index_line] = (t_vertex *)malloc(nb_cols * sizeof(t_vertex));
		if (matrix[index_line] == NULL)
			break ;
		i = 0;
		while (i < nb_cols)
		{
			add_vertex(i, matrix_char[index_line][i], matrix, index_line);
			++i;
		}
		++index_line;
	}
	return (matrix);
}
