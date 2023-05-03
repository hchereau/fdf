/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:45:31 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/03 16:24:26 by hchereau         ###   ########.fr       */
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

//void create_char_matrice_test(void)
//{
//    struct s_matrice    matrice;
//    char                *matrice_test1[] = {"0000", "0000"};
//    int                 fd1;

//    printf("\nCREATE_CHAT_MATRICE_TEST\n\n");
//    fd1 = open("fdf_tester/maps/test.fdf", O_RDONLY);
//    create_char_matrice(fd1, &matrice);
//    check_matrix_eq(matrice.matrice_char, matrice_test1, matrice.size_y, matrice.size_x, 1);
//}
