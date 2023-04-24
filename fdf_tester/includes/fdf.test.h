/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:29:58 by hchereau          #+#    #+#             */
/*   Updated: 2023/04/24 17:00:38 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TEST_H
# define FDF_TEST_H

# include "fdf.h"

# define GREEN "\033[32;1m"
# define RED "\033[31;1m"
# define WHITE "\033[0m"

void    count_word_test(void);
void    get_size_matrice_test(void);
void    create_char_matrice_test(void);
void    print_matrix(char **mat);
void    ft_csplit_test(void);
void    check_matrix_eq(char **mata, char **matb, size_t size_y, size_t size_x, const size_t n);
void    check_sizet_eq(const size_t a, const size_t b, const size_t n);
void    check_chain_eq(const char *a, const char *b, const size_t n);

#endif