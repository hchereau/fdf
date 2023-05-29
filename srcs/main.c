/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:17:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/29 22:41:32 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// int main(void)
// {
//     int fd;
//     t_matrice matrice;


//     matrice.size_x = 0;
//     matrice.size_y = 0;
//     fd = open("test.txt", O_RDONLY);
//     get_size_matrice(fd, &matrice);
//     printf("x = %ld\n y = %ld", matrice.size_x, matrice.size_y);
//     close(fd);
// }

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

int	main(__attribute__((unused))int argc, char **argv)
{
	int			fd;
	size_t		nb_line;
	t_vertex	**matrix;
	char		***matrix_char;

	fd = open(argv[1], O_RDONLY);
	nb_line = get_nb_line(fd);
	matrix_char = create_char_matrix(fd, nb_line);
	close(fd);
	if (matrix_char != NULL && is_valid_matrix(matrix_char, nb_line))
	{
		fd = open(argv[1], O_RDONLY);
		matrix = create_vertex_matrix(fd, nb_line, matrix_char);
		print_matrix(matrix, nb_line, count_point_on_line(matrix_char));
	}
	free_matrice_char(matrix_char);
}
