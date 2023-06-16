/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:20:53 by hchereau          #+#    #+#             */
/*   Updated: 2023/06/16 19:17:37 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	shut_window(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free_matrix_vertex(window);
	exit(0);
}

int	key_events(int keycode, t_window *window)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		shut_window(window);
	zoom(keycode, window);
	return (1);
}

void	test_hook_key(t_window	*window)
{
	mlx_key_hook(window->win_ptr, key_events, window);
	mlx_hook(window->win_ptr, 17, 0L, shut_window, window);
}
