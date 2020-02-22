/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jony <jony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:19:54 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/19 20:43:11 by jony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_error(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

void win_interface(t_fdf *data)
{
	if (data->height > 300 || data->width > 300)
	{
		data->zoom = 1;
		data->map_h = 1300;
		data->map_w = 2400;
	}
	else if (data->height > 200 || data->width > 200)
	{
		data->zoom = 2;
		data->map_h = 1200;
		data->map_w = 2200;
	}
	else if (data->height > 100 || data->width > 100)
	{
		data->zoom = 4;
		data->map_h = 1000;
		data->map_w = 2000;
	}
	else if (data->height > 25 || data->width > 25)
	{
		data->zoom = 8;
		data->map_h = 1000;
		data->map_w = 1600;
	}
}

void setup_image(t_fdf *data)
{
	data->zoom = 25;
	data->map_h = 800;
	data->map_w = 1000;
	data->color = 0xFFFFFF;
	data->altitude = 1;
	data->palette = TRENDY;
	data->projection = ISOMETRIC;
	win_interface(data);
	data->pos_x = data->map_w / 2 - (data->map_w / 15);
	data->pos_y = 200;
}

int key_controls(int key, t_fdf *data)
{
	if (key == 53)
		exit(0);
	else if (key == 8)
		mlx_clear_window(data->mlx, data->win);
	else if (key == 34)
		data->projection = ISOMETRIC;
	else if (key == 35)
		data->projection = PARALLEL;
	else if (key == 17)
		data->palette = TRENDY;
	else if (key == 3)
		data->palette = FRUIT;
	draw(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf *data;

	if (!(data = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(1);
	if (argc != 2)
	{
		ft_error("Number of arguments are wrong!");
		return (1);
	}
	read_file(argv[1], data);
	setup_image(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_w, data->map_h, "FDF");
	draw(data);
	mlx_hook(data->win, 2, 0, key_controls, data);
	mlx_loop(data->mlx);
	return (0);
}
