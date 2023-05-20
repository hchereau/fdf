/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:02:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/20 21:14:06 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_vertex(size_t i, char **s, t_vertex ***matrix)
{
	char	**vertex_point;

	vertex_point = ft_split(s, ',');
	matrix[i]->x = i;
	matrix[i]->z = vertex_point[0];
	if (vertex_point[1] != NULL)
		matrix[i]->color = vertex_point[1];
	else
		matrix[i]->color = 0xFFFFFFF;
}

t_vertex	***create_vertex_matrix(int fd, size_t nb_line, char ***matrix)
{
	struct s_vertex	***matrix;
	size_t			index_line;
	size_t			nb_cols;
	size_t			i;
	char			**split_point;

	index_line = 0;
	nb_cols = count_point_on_line(matrix);
	matrix = (t_vertex ***)malloc(nb_line * sizeof(t_vertex **));
	while ((index_line < nb_line) && matrix != NULL)
	{
		matrix[index_line] = (t_vertex **)malloc(nb_cols * sizeof(t_vertex *));
		split_point = csplit(get_nb_line(fd), WHITESPACE);
		i = 0;
		while (split_point[i] != NULL)
		{
			add_vertex(index_line, split_point, &matrix);
			++i;
		}
		++index_line;
	}
}
