/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:07:51 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/04 14:37:28 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the last occurrence of the char c in the string pointed to,
** by the argument str.
** In the first loop we searches the str for the last occurence char.
** With ++str we increment the value and than return it. It will be stored in
** last.
*/

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = (0);
	while (*str)
	{
		if (*str == c)
			last = (char*)str;
		++str;
	}
	if (last)
		return (last);
	if (c == '\0')
		return ((char*)str);
	return (0);
}
