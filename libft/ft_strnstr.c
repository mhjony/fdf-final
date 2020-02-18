/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:28 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/04 18:16:26 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurence of the null-terminated string little int the
** string big, where not more than len characters are searched. Characters
** that appear after a \0 charactre are not searched.
** If little is an empty string, big is returned.
** If little occurs nowhere in big, NULL is returned, otherwise
** a pointer to the first char of the first occurrence of little is returned.
** In the second while we try to search for similiaraties in both strings, if
** it finds a string which matches lets, it will save the postion where it
** matches in [i] and returns it with big + i, fromt that point everything will
** be printed out.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && i + j < len && little[j] &&
				big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
