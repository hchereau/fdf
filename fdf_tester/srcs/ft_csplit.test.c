/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csplit.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:22 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/24 21:05:11 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void    ft_csplit_test(void)
{
    char *str1 = "a b c ddddd    e ";
    char *rep[] = {"a", "b", "c", "ddddd", "e", NULL};
    
    printf("\nFT_CSPLIT_TEST\n\n");
    check_matrix_eq(ft_csplit(str1, " \t\n\b"), rep, 4, 1, 1);
}