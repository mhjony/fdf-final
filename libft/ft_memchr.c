/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:31:20 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the first occurrence of the character c in the first n bytes
** of the stirng pointed to, by the argument str.
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmpstr;
	unsigned char	tmpc;
	size_t			i;

	tmpstr = (unsigned char*)str;
	tmpc = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (tmpstr[i] == tmpc)
		{
			return ((void*)&tmpstr[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
