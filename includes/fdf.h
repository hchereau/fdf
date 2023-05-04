/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:25:16 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/04 14:12:54 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include "libft.h"

# define WHITESPACE " \t\n"

size_t    get_nb_line(int fd);
char	***create_char_matrix(int fd, size_t nb_line);
char	**ft_csplit(const char *s, char *charset);
void	free_strs(char **strs);
size_t  ft_strlen_mat(char **matrice);

#endif
