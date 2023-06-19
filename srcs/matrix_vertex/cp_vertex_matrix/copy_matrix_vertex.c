/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:11:37 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/19 11:04:54 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	**malloc_matrix(size_t nb_line, size_t nb_cols)
{
	size_t		i;
	t_vertex	**matrix;

	i = 0;
	matrix = (t_vertex **)malloc(nb_line * sizeof(t_vertex *));
	while (i < nb_line && matrix != NULL)
	{
		matrix[i] = (t_vertex *)malloc(nb_cols * sizeof(t_vertex));
		if (matrix[i] == NULL)
			return (NULL);
		++i;
	}
	return (matrix);
}

static void	cp_matrix_line(t_vertex **matrix_cp, t_vertex **matrix,
		size_t index_line, size_t nb_cols)
{
	size_t	index_cols;

	index_cols = 0;
	while (index_cols < nb_cols)
	{
		matrix_cp[index_line][index_cols] = matrix[index_line][index_cols];
		++index_cols;
	}
}

t_vertex	**cp_matrix_vertex(t_vertex **matrix, size_t nb_line,
		size_t nb_cols)
{
	size_t		index_line;
	t_vertex	**cp_matrix;

	index_line = 0;
	cp_matrix = malloc_matrix(nb_line, nb_cols);
	while (index_line < nb_line)
	{
		cp_matrix_line(cp_matrix, matrix, index_line, nb_cols);
		++index_line;
	}
	return (cp_matrix);
}
