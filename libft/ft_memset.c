/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:10:09 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the character c (an unsigned char) to the first n characters of the
** string pointed to, by the argument str.
** Returns a pointer to the memory area str.
*/

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	char			*tmp;
	unsigned char	tmpc;

	i = 0;
	tmp = (char*)str;
	tmpc = (unsigned char)c;
	while (n > 0)
	{
		tmp[i] = tmpc;
		i++;
		n--;
	}
	return (str);
}
