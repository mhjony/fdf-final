/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:20:55 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*tmpdst;
	char	*tmpsrc;

	if (!str1 && !str2)
		return (NULL);
	tmpdst = (char*)str1;
	tmpsrc = (char*)str2;
	i = 0;
	while (n > 0)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
		n--;
	}
	return (str1);
}
