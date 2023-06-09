/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:02:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/08 15:22:30 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	index_line = 0;
	nb_cols = count_point_on_line(matrix_char);
	matrix = (t_vertex **)malloc(nb_line * sizeof(t_vertex *));
	while ((index_line < nb_line) && matrix != NULL)
	{
		fill_matrix_line(matrix, matrix_char, index_line, nb_cols);
		++index_line;
	}
	return (matrix);
}
