/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:26:17 by ismelich          #+#    #+#             */
/*   Updated: 2020/02/03 12:04:06 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the first occurrence of the character c in the string
** pointed to by the argument str. str=World c=r return=rld
*/

char	*ft_strchr(const char *str, int c)
{
	char *a;

	a = (char *)str;
	while (*a != c)
	{
		if (!*a)
		{
			return (NULL);
		}
		a++;
	}
	return (a);
}
