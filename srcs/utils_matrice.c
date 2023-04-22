/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:05 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/22 18:23:31 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t   word_count(char *str)
{
    bool    in_word;
    size_t  nb_word;

    in_word = false;
    nb_word = 0;

    if (str == NULL)
        return (0);
    while (*str != '\0')
    {
        if ((*str < 9 || *str > 13) && *str != 32)
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

void    get_size_matrice(int fd, t_matrice *matrice)
{
    char    *gnl = NULL; 
    
    gnl = get_next_line(fd);
    matrice->size_x = word_count(gnl);
    while (gnl != NULL)
    {
        ++matrice->size_y;
        gnl = get_next_line(fd);
    }
}

void    create_char_matrice(t_matrice *matrice)
{
    size_t i;
    
    i = 0;
    matrice->matrice_char = (char **)malloc(size_y * sizeof(char));
    while (i < size_y)
    {
        matrice[i] = (char)malloc(size_y * sizeof(char));
        ft_strlcpy(get_next_line(fd), matrice[i], size_x);
        ++i;
    }
}

// int main(void)
// {
//     int fd;
//     t_matrice matrice;


//     matrice.size_x = 0;
//     matrice.size_y = 0;
//     fd = open("test.txt", O_RDONLY);
//     get_size_matrice(fd, &matrice);
//     printf("x = %ld\n y = %ld", matrice.size_x, matrice.size_y);
//     close(fd);
// }



