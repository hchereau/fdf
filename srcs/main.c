/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:17:43 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/09 17:26:05 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	t_vertex	**cp_matrix;
	size_t		count_p;

	count_p = count_point_on_line(matrix_char);
	matrix = create_vertex_matrix(nb_line, matrix_char);
	malloc_matrix(nb_line, count_p, cp_matrix);
	cp_matrix = cp_matrix_vertex(matrix, nb_line, count_p);
	free_matrix_char(matrix_char);
	print_matrix(cp_matrix, nb_line, count_p);
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
		{
			vertex_matrix(nb_line, matrix_char);
		}
		else
			ft_printf("error: invalid map\n");
		free_matrix_char(matrix_char);
	}
	else
		printf("error: invalid file\n");
}
