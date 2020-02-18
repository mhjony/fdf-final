/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:07:10 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates the requested memory and returns a pointer to it.
*/

void	*ft_memalloc(size_t size)
{
	void	*res;
	char	*reschar;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (res == NULL)
	{
		return (NULL);
	}
	reschar = (char*)res;
	while (i < size)
	{
		reschar[i] = '\0';
		i++;
	}
	return (res);
}
