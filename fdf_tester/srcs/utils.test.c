/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:50:51 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/23 17:07:11 by hchereau         ###   ########.fr       */
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

void    check_chain_eq(const char *a, const char *b, const size_t n)
{
    size_t  ia;
    size_t  ib;

    ia = 0;
    ib = 0;
    while (a[ia] != '\0' && b[ib] != '\0')
    {
        if (ia != ib)
        {
            printf("%zu : %sKO%s\n", n, RED, WHITE);
            printf("(mine) [%c] : (expected) [%c] \n", a[ia], b[ib]);    
            return ;
        }
        ++ia;
        ++ib;
    }
    if (ia == ib)
        printf("%zu : %sOK%s\n", n, GREEN, WHITE);
    else
    {
            printf("%zu : %sKO%s\n", n, RED, WHITE);
            printf("size error | (mine) [%zu] : (expected) [%zu] \n", ia, ib);    
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
        while(x < size_x)
        {
            if (mata[y][x] != matb[y][x])
            {
                printf("%zu : %sKO%s\n", n, RED, WHITE);
                printf("cord (%zu, %zu) | mine [%c] : (expected) [%c] \n", y, x, mata[y][x], matb[y][x]);
                return ;
            }
            ++x;
        }
        ++y;   
    }
    printf("%zu : %sOK%s\n", n, GREEN, WHITE);
}