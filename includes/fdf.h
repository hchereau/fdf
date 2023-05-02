/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/02 18:57:05 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"

# define WHITESPACE " \t\b\n"

typedef struct s_matrice{
    size_t  size_y;
    size_t  size_x;
    char     ***matrice_char;
}   t_matrice;

size_t	word_count(char *str);
size_t    get_nb_line(int fd);
// void    create_char_matrice(int fd, t_matrice *matrice);
char	**ft_csplit(const char *s, char *charset);
void	free_strs(char **strs);
size_t  ft_strlen_mat(char **matrice);

#endif
