/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrice_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:02:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/02 18:52:18 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_matrix_char(t_matrice *matrice, int fd)
{
	size_t	index_col;

	index_col = 0;
	while(index_col < matrice->y)
	{

		++index_col
	}
}

-------------------

char ***content;

content = read_file(file_path);
if (is_valid_map(content) == true)
{
	map = get_map(content);
	print_map(map);
}
