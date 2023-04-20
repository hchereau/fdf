/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:05 by hchereau          #+#    #+#             */
/*   Updated: 2023/03/18 20:50:42 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t   word_count(char *str)
{
    bool    in_word;
    size_t  nb_word;

    in_word = false;
    nb_word = 0;
    while (str != '\0')
    {
        if (str < 9 || str > 13 && str != 32)
        {
            if (in_word == false)
            {
                ++nb_word;
                in_word = true;
            }
        }
        else
            in_word = false;
        ++str;
    }
    return (nb_word);
}
