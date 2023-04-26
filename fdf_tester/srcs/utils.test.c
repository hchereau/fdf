/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:50:51 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/24 19:48:39 by hchereau         ###   ########.fr       */
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

void    check_matrix_eq(char **mata, char **matb, size_t size_y, size_t size_x, const size_t n)
{
    size_t  y;
    size_t  x;
    
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
                printf("(mine matrix) : \n");
                print_matrix(mata);
                printf("(expected matrix) : \n");
                print_matrix(matb);
                return ;
            }
            ++x;
        }
        ++y;   
    }
    printf("%zu : %sOK%s\n", n, GREEN, WHITE);
}

void    print_matrix(char **mat)
{
    size_t  y;

    y = 0;
    while(mat[y] != NULL)
    {
        ft_putchar_fd('[', 1);
        ft_putstr_fd(mat[y], 1);
        ft_putchar_fd(']', 1);
        printf("\n");
        ++y;
    }
    return ;
}