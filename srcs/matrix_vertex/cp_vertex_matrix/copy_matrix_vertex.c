/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:11:37 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/09 11:57:37 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	**malloc_matrix(size_t nb_line, size_t nb_cols)
{
	size_t	i;

	i = 0;
	matrix = (t_vertex **)malloc(nb_line * sizeof(t_vertex *));
	while(i < nb_line && matrix != NULL)
	{
		matrix[i] = (t_vertex *)malloc(nb_cols * sizeof(t_vertex));
		if (matrix[i] == NULL)
			return (NULL);
		++i;
	}
}

void	cp_matrix_vertex(t_vertex **matrix, t_window w, t_vertex **cp_matrix)
{
	size_t	index_line;

	index_line = 0;
	while(index_line < w.map.nb_line)
	{
		cp_matrix_line(matrix_copy, matrix, w, index_line)
		++index_line;
	}
}

cp_matrix_line(matrix_copy, matrix, w, index_line)
{
	
}

