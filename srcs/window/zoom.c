/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:57:18 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/19 10:57:48 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_window *window)
{
	if (keycode == 65453)
		window->map.zoom -= ZOOM;
	if (keycode == 65451 && window->map.zoom > 0)
		window->map.zoom += ZOOM;
}
