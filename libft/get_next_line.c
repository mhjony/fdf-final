/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:38:30 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/13 17:25:45 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_nline(char **stack, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*stack)[len] != '\n' && (*stack)[len] != '\0')
		len++;
	if ((*stack)[len] == '\n')
	{
		*line = ft_strsub(*stack, 0, len);
		tmp = ft_strdup(*stack + len + 1);
		free(*stack);
		*stack = tmp;
		if (*stack[0] == '\0')
			ft_strdel(stack);
	}
	else if ((*stack)[len] == '\0')
	{
		*line = ft_strdup(*stack);
		ft_strdel(stack);
	}
	return (1);
}

int	ft_return(char **stack, int n, char **line)
{
	if (n < 0)
		return (-1);
	else if (n == 0 && (*stack) == NULL)
		return (0);
	else
		return (search_nline(stack, line));
}

int	get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	static char	*stack;
	int			n;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((n = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (stack == NULL)
			stack = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(stack, buffer);
			free(stack);
			stack = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_return(&stack, n, line));
}
