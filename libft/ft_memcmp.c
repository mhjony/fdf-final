/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:23:42 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first n bytes of memory are str1 and memory area str2.
** The return will be int that shows the difference on the ascii table.
*/

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tmpstr1;
	unsigned char	*tmpstr2;
	size_t			i;

	tmpstr1 = (unsigned char*)str1;
	tmpstr2 = (unsigned char*)str2;
	i = 0;
	while (n > 0)
	{
		if (tmpstr1[i] != tmpstr2[i])
		{
			return ((int)(tmpstr1[i] - tmpstr2[i]));
		}
		i++;
		n--;
	}
	return (0);
}
