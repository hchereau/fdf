/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/29 22:13:40 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"

typedef struct s_matrice{
    size_t  size_y;
    size_t  size_x;
    char     **matrice_char;
}   t_matrice;

size_t  word_count(char *str);
void    get_size_matrice(int fd, t_matrice *matrice);
// void    create_char_matrice(int fd, t_matrice *matrice);
char	**ft_csplit(const char *s, char *charset);
void	free_strs(char **strs);

#endif