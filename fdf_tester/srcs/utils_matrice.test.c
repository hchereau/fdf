/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:45:31 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/30 01:07:28 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void get_nb_line_test(void)
{
	int	fd1;

	fd1 = open("fdf_tester/maps/test.fdf", O_RDONLY);
	printf("\nGET_NB_LINE_TEST\n\n");
	check_sizet_eq(get_nb_line(fd1), 2, 1);
	close(fd1);
}

void	ft_strlen_mat_test(void)
{
	char	*tab[] = {"0", "0", "0", NULL};
	printf("\nFT_STRLEN_MAT_TEST\n\n");
	check_sizet_eq(ft_strlen_mat(tab), 3, 1);
}

void	create_char_matrix_test(void)
{
	size_t	nb_line;
	size_t	fd1;
	char	***matrix;
	char ***matrix = {
    {{"0"}, {"0"}, {"0"}, {"0"}, NULL},
    {{"0"}, {"0"}, {"0"}, {"0"}, NULL}
	NULL
	};

	printf("\nCREATE_CHAR_MATRIX_TEST\n\n");
	fd1 = open("fdf_tester/maps/test.fdf", O_RDONLY);
	nb_line = get_nb_line(fd1);
	matrix = create_char_matrix(fd1, nb_line);
	check_matrix_eq(matrix, (char ***)matrix, 1);
	close(fd1);
	free(matrix);
}
