/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:39:49 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/14 12:37:50 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 50, 50, 0x1C799E, "Options");
	mlx_string_put(data->mlx, data->win, 50, 70, 0x1C799E, "ESC for exit");
	mlx_string_put(data->mlx, data->win, 50, 90, 0x1C799E, "I for ISOMETRIC");
	mlx_string_put(data->mlx, data->win, 50, 110, 0x1C799E, "P for PARALLEL");
	mlx_string_put(data->mlx, data->win, 50, 130, 0x1C799E, "F for FRUIT");
	mlx_string_put(data->mlx, data->win, 50, 150, 0x1C799E, "I for TRENDY");
}

/*
** This bresenham Algorithm
*/

static void	draw_pixel(t_fdf *data, t_draw start, t_draw end)
{
	t_var var;

	var.dx = ft_abs(end.x - start.x);
	var.sx = start.x < end.x ? 1 : -1;
	var.dy = -ft_abs(end.y - start.y);
	var.sy = start.y < end.y ? 1 : -1;
	var.err = var.dx + var.dy;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(data->mlx, data->win, data->pos_x + start.x, \
		data->pos_y + start.y, data->color);
		if (start.x == end.x && start.y == end.y)
			break ;
		var.e2 = 2 * var.err;
		if (var.e2 >= var.dy)
		{
			var.err += var.dy;
			start.x += var.sx;
		}
		if (var.e2 <= var.dx)
		{
			var.err += var.dx;
			start.y += var.sy;
		}
	}
}

/*
** draw_lines function giving all information to "draw_pixels"
** function to draw a straight line
*/

void		draw_lines(t_fdf *data, t_draw start, t_draw end)
{
	t_draw	*info;

	if (!(info = (t_draw*)malloc(sizeof(t_draw))))
		exit(-1);
	info->z = data->map[start.y][start.x] * data->altitude;
	info->z2 = data->map[end.y][end.x] * data->altitude;
	info->x = start.x * data->zoom;
	info->x2 = end.x * data->zoom;
	info->y = start.y * data->zoom;
	info->y2 = end.y * data->zoom;
	if (data->projection == ISOMETRIC)
		projection(info);
	start.x = info->x;
	start.y = info->y;
	end.x = info->x2;
	end.y = info->y2;
	draw_pixel(data, start, end);
	free(info);
}

void		set_coordinates(t_fdf *data, int x, int y)
{
	t_draw	coordinates[2];

	color(data, x, y);
	coordinates[0].x = x;
	coordinates[0].y = y;
	if (x < data->width - 1)
	{
		coordinates[1].x = x + 1;
		coordinates[1].y = y;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
	if (y < data->height - 1)
	{
		coordinates[1].x = x;
		coordinates[1].y = y + 1;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
}

void		draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	print_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_coordinates(data, x, y);
			x++;
		}
		y++;
	}
}
