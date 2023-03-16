/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchereau <hchereau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:20:04 by hchereau          #+#    #+#             */
/*   Updated: 2023/03/12 16:20:02 by hchereau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_circle
{
    int			x;
    int			y;
    int			radius;
    int			color;
}				t_circle;

typedef struct	s_data
{
    void	*mlx;
    void	*win;
}				t_data;

void draw_circle(t_data *data, t_circle circle)
{
    int x = 0;
    int y = circle.radius;
    int p = (5 - circle.radius * 4) / 4;
    int color = circle.color;

    while (x <= y)
    {
        mlx_pixel_put(data->mlx, data->win, circle.x + x, circle.y + y, color);
        mlx_pixel_put(data->mlx, data->win, circle.x + y, circle.y + x, color);
        mlx_pixel_put(data->mlx, data->win, circle.x - x, circle.y + y, color);
        mlx_pixel_put(data->mlx, data->win, circle.x - y, circle.y + x, color);
        mlx_pixel_put(data->mlx, data->win, circle.x + x, circle.y - y, color);
        mlx_pixel_put(data->mlx, data->win, circle.x + y, circle.y - x, color);
        mlx_pixel_put(data->mlx, data->win, circle.x - x, circle.y - y, color);
        mlx_pixel_put(data->mlx, data->win, circle.x - y, circle.y - x, color);
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

int exit_program(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_loop_end(data->mlx);
    return (0);
}
/*
int main()
{
    t_data		data;
    t_circle	my_circle = {100, 100, 50, 0xFF0000};

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Ma fenetre");

    draw_circle(&data, my_circle);

    mlx_hook(data.win, 17, 0L, exit_program, &data);
    mlx_loop(data.mlx);

    return 0;
}
*/
/*
typedef struct  s_square
{
    int     x;
    int     y;
    int     size;
}               t_square;

void	draw_square(t_data *data, t_square square, int color)
{
    int		x;
    int		y;

    y = square.y;
    while (y < square.y + square.size)
    {
        x = square.x;
        while (x < square.x + square.size)
        {
            mlx_pixel_put(data->mlx, data->win, x, y, color);
            x++;
        }
        y++;
    }
}

int		main(void)
{
    t_data  data;
    t_square square;

    square.x = 100;
    square.y = 100;
    square.size = 50;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "Ma fenetre");

    draw_square(&data, square, 0xFFFFFF);

    mlx_hook(data.win, 17, 0L, exit_program, &data);
    mlx_loop(data.mlx);
    return (0);
}
*/
typedef struct segment
{
    int abs_a;
    int ord_a;
    int abs_b;
    int ord_b;
}   t_segment;

void draw_segment(t_data *data, t_segment *segment, int color)
{
    int dx = segment->abs_b - segment->abs_a;
    int sx = dx > 0 ? 1 : -1;
    int dy = segment->ord_b - segment->ord_a;
    int sy = dy > 0 ? 1 : -1;
    int err = 0;

    dx = dx * sx;
    dy = dy * sy;

    int x = segment->abs_a;
    int y = segment->ord_a;

    while (x != segment->abs_b || y != segment->ord_b)
    {
        mlx_pixel_put(data->mlx, data->win, x, y, color);
        if (err + dy < dx)
        {
            err += dy;
            x += sx;
        }
        else
        {
            err -= dx;
            y += sy;
        }
    }
}

int main(void)
{
    t_data      data;
    t_segment   segment;
    
    segment.abs_a = 1000;
    segment.ord_a = 100000;
    segment.abs_b = 100;
    segment.ord_b = 100;
    
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1920, 1080, "segment");
    
    draw_segment(&data, &segment, 0xFFFFFF);

    mlx_hook(data.win, 17, 0L, exit_program, &data);
    mlx_loop(data.mlx);
    
    
}
