/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:50:51 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/22 18:32:54 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void    check_sizet_eq(const size_t a, const size_t b, const size_t n)
{
    if (a == b)
        printf("%zu : %sOK%s\n", n, GREEN, WHITE);
    else
    {
        printf("%zu : %sKO%s\n", n, RED, WHITE);
        printf("(mine) [%zu] : (expected) [%zu] \n", a, b);
    }
}

void    check_matrix_eq(const char **mata, const char **matb, size_t size_y, size_t size_x, const size_t n)
{
    bool is_valid;
    size_t  y;
    size_t  x;
    
    is_valid = true
    y = 0;
    x = 0;
    
    while(y < size_y)
    {
        if ()
    }
}