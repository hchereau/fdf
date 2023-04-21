/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:50:51 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/22 00:01:22 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.test.h"

void    check_sizet_eq(const size_t a, const size_t b, const size_t n)
{
    if (a == b)
        printf("%zu : %sOK%s\n", n, GREEN, WHITE);
    else
    {
        printf("%zu : %sOK%s\n", n, RED, WHITE);
        printf("(mine) [%zu] : (expected) [%zu] \n", a, b);
    }
}