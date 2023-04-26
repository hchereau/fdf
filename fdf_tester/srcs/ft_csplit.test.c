/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csplit.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:39:22 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/26 13:18:09 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void    ft_csplit_test(void)
{
    char    *str1 = "a b c ddddd    e ";
    char    *str2 = "salut";
    char    *rep1[] = {"a", "b", "c", "ddddd", "e", NULL};
    char    *rep2[] = {"salut", NULL};
    
    
    printf("\nFT_CSPLIT_TEST\n\n");
    check_matrix_eq(ft_csplit(str1, " \t\n\b"), rep1, 4, 1, 1);
    check_matrix_eq(ft_csplit(str2, " \t\n\b"), rep2, 1, 2, 2);
    free(str1);
    free(str2);
}