/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:17:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/30 15:18:07 by hchereau         ###   ########.fr       */
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

static	char	***char_matrix(char	*path, size_t *nb_line)
{
	int		fd;
	char	***matrix;

	fd = open(path, O_RDONLY);
	*nb_line = get_nb_line(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	matrix = create_char_matrix(fd, *nb_line);
	close(fd);
	return (matrix);
}

static	void	vertex_matrix(size_t nb_line, char ***matrix_char)
{
	t_vertex	**matrix;

	matrix = create_vertex_matrix(nb_line, matrix_char);
	print_matrix(matrix, nb_line, count_point_on_line(matrix_char));
}

static	bool	is_valid_path(int argc, char **argv)
{
	int		len_arg;
	bool	is_valid;

	is_valid = false;
	if (open(argv[1], O_RDONLY) != -1)
	{
		if (argc == 2)
		{
			len_arg = ft_strlen(argv[1]);
			if (ft_strncmp(argv[1] + (len_arg - 4), ".fdf", 4) == 0)
				is_valid = true;
		}
	}
	return (is_valid);
}

int	main(int argc, char **argv)
{
	size_t		nb_line;
	char		***matrix_char;

	if (is_valid_path(argc, argv))
	{
		matrix_char = char_matrix(argv[1], &nb_line);
		if (matrix_char != NULL && is_valid_matrix(matrix_char, nb_line))
			vertex_matrix(nb_line, matrix_char);
		else
			ft_printf("error: invalid map\n");
		free_matrice_char(matrix_char);
	}
	else
		printf("error: invalid argument\n");
}
