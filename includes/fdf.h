/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/02 17:06:13 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"

# define WHITESPACE " \t\b\n"

typedef struct s_mat{
    size_t  size_y;
    size_t  size_x;
    char     **matrice_char;
}   t_mat;

typedef struct s_matrice{
    size_t  size_y;
    size_t  size_x;
    char     ***matrice_char;
}   t_matrice;

size_t	word_count(char *str);
void	get_size_matrice(int fd, t_mat *matrice);
// void    create_char_matrice(int fd, t_matrice *matrice);
char	**ft_csplit(const char *s, char *charset);
void	free_strs(char **strs);
size_t  ft_strlen_mat(char **matrice);

#endif
