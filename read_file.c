/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:47:52 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/13 20:58:47 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Map_size function calculate the width and height of the map
** and assign it to t_fdf structure height and width.
*/

void	map_size(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_error("Invalid Map");
	}
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		width = ft_words_counter(line);
		free(line);
	}
	if (close(fd) == -1)
	{
		ft_error("File can not be closed");
	}
	data->height = height;
	data->width = width;
}

/*
** In this malloc-z function I allocate
** the memory based on height and width
*/

void	malloc_z(t_fdf *data)
{
	int	i;

	if (!(data->map = (int **)malloc(sizeof(t_fdf *) * (data->height + 1))))
		exit(1);
	i = 0;
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(t_fdf) * (data->width + 1));
		if (!data->map[i])
			exit(1);
		i++;
	}
}

/*
** This fill_map function converts strings to integers
*/

void	fill_map(int *line_z, char *line)
{
	int		i;
	char	**map;

	map = ft_strsplit(line, ' ');
	i = 0;
	while (map[i])
	{
		line_z[i] = ft_atoi(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

void	read_file(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	map_size(file, data);
	if (data->width == 0 || data->height == 0)
		ft_error("Your map is not valid");
	malloc_z(data);
	if ((fd = open(file, O_RDONLY)) < 0)
		exit(1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(data->map[i], line);
		free(line);
		i++;
	}
}
