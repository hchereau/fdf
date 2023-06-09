/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:15:54 by hchereau          #+#    #+#             */
/*   Updated: 2023/05/28 15:50:18 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	base_convert(char *convert, char *base)
{
	size_t			i;
	const size_t	len_base = ft_strlen(base);

	i = 0;
	if (convert[0] == '\0')
		return (0);
	while (convert[0] != base[i])
		++i;
	return (i + base_convert(convert + 1, base) * len_base);
}
