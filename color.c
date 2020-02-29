/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:28:54 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/14 13:53:02 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fruit_color(t_fdf *data, int x, int y)
{
	int	z;

	z = data->map[y][x];
	if (z * data->altitude < 0)
		data->color = 0x009292;
	else
		data->color = 0xF65156;
}

void	trendy_color(t_fdf *data, int x, int y)
{
	int	z;

	z = data->map[y][x];
	if (z * data->altitude < 0)
		data->color = 0xCC1A99;
	else
		data->color = 0x6FFF5E;
}

void	color(t_fdf *data, int x, int y)
{
	if (data->palette == FRUIT)
		fruit_color(data, x, y);
	else if (data->palette == TRENDY)
		trendy_color(data, x, y);
}
