/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:45:31 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/22 00:29:16 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void    count_word_test(void)
{
    printf("\nCOUNT_WORD_TEST\n\n");
    check_sizet_eq(word_count("salut ca va"), 3, 1);
    check_sizet_eq(word_count(""), 0, 2);
    check_sizet_eq(word_count("salutaaaaaaaa"), 1, 3);
    
}

void get_size_matrice(void)
{
    struct s_matrice matrice;

    matrice.size_y = 0;
    matrice.size_x = 0;
    
}