/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:05 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/01 14:47:31 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_nb_line(int fd)
{
	char	*gnl;
	size_t	nb_line;

	nb_line = 0;
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		++nb_line;
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	return (nb_line);
}

size_t	ft_strlen_mat(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i]!= NULL)
		++i;
	return (i);
}

char	***create_char_matrix(int fd, size_t nb_line)
{
	size_t	index_line;
	char	***matrix;
	char	**tab_cont;
	char	*gnl;

	matrix = (char ***)malloc((nb_line + 1) * sizeof(char **));
	index_line = 0;
	while (index_line < nb_line)
	{
		gnl = get_next_line(fd);
		tab_cont = ft_csplit(gnl, WHITESPACE);
		matrix[index_line] = tab_cont;
		free(gnl);
		++index_line;
	}
	matrix[index_line] = NULL;
	return (matrix);
}

static size_t	first_column(char **line)
{
	size_t	nb_car;

	nb_car = 0;
	while (line[nb_car] != NULL)
		++nb_car;
	return (nb_car);
}

bool	is_valid_matrix(char ***matrix, size_t nb_line)
{
	size_t	y;
	size_t	x;
	size_t	nb_col;
	bool	is_matrix;

	y = 1;
	nb_col = first_column(matrix[0]);
	is_matrix = true;
	while (y < nb_line)
	{
		x = 0;
		while (matrix[y] != NULL
			&& matrix[y][x] != NULL && x < nb_col)
			++x;
		if (x != nb_col)
		{
			is_matrix = false;
			break ;
		}
		++y;
	}
	return (is_matrix);
}

