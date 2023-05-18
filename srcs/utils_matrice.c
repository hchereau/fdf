/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:05 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/17 15:15:55 by hchereau         ###   ########.fr       */
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

size_t	ft_strlen_mat(char **matrice)
{
	size_t	i;

	i = 0;
	while (matrice[i]!= NULL)
		++i;
	return (i);
}

char	***create_char_matrix(int fd, size_t nb_line)
{
	size_t	index_line;
	char	***matrix;
	char	**tab_cont;

	matrix = (char ***)malloc(nb_line * sizeof(char **));
	index_line = 0;
	while (index_line < nb_line)
	{
		tab_cont = ft_csplit(get_next_line(fd), WHITESPACE);
		matrix[index_line] = tab_cont;
		++index_line;
		free(tab_cont);
	}
	free(tab_cont);
	return (matrix);
}

bool	is_valid_matrice(char ***matrix, size_t nb_line)
{
	size_t	y;
	size_t	x;
	size_t	nb_col;
	bool	is_matrix;

	y = 1;
	nb_col = first_column(matrix[y]);
	is_matrix = true;
	while (y < nb_line)
	{
		x = 0;
		while (matrix[y][x] != NULL && x < nb_col)
		++x;
	}
	if (x > nb_col)
		is_matrix = false;
	return (is_matrix);
}

size_t	first_column(char **line)
{
	size_t	nb_car;

	while (line[nb_car] != NULL)
		++nb_car;
	return (nb_car);
}
