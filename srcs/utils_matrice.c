/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:44:05 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/02 18:56:42 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t    get_nb_line(int fd)
{
    char	*gnl;
	size_t	nb_line;

	nb_line = 0;
    gnl = get_next_line(fd);
    while (gnl != NULL)
    {
        ++nb_line;
		free(gnl);
        gnl = get_next_line(fd);
    }
    free(gnl);
	return(nb_line);
}

size_t  ft_strlen_mat(char **matrice)
{
	size_t	i;

    i = 0;
	while(matrice[i]!= NULL)
		++i;
	return (i);
}

//void    create_char_matrice(int fd, t_matrice *matrice)
//{

//}

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



