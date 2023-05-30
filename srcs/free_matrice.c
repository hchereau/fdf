/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:56:48 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/30 18:23:36 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrice_char(char ***matrix_char)
{
	int	i;
	int	y;

	i = 0;
	while (matrix_char[i] != NULL)
	{
		y = 0;
		while (matrix_char[i][y])
		{
			free(matrix_char[i][y]);
			++y;
		}
		free(matrix_char[i]);
		++i;
	}
	free(matrix_char);
}

// void	free_matrice_vertex(t_vertex **matrix_vertex)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (matrix_vertex)
// }
