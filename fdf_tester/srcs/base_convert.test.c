/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:30:10 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/28 15:50:33 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void	create_vertex_matrix_test(void)
{
	char		*hexa = "E8";
	const int		res = 142;
	int				sortie;

	printf("\nCREATE_VERTEX_MATRIX_TEST\n\n");
	sortie = base_convert(hexa, BASE_HEXA);
	check_int_eq(sortie, res, 1);
	printf("\nen hexa: %X\n", sortie);



}

