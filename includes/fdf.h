/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/03 17:01:00 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"

# define WHITESPACE " \t\n"

size_t	word_count(char *str);
size_t    get_nb_line(int fd);
// void    create_char_matrice(int fd, t_matrice *matrice);
char	**ft_csplit(const char *s, char *charset);
void	free_strs(char **strs);
size_t  ft_strlen_mat(char **matrice);

#endif
