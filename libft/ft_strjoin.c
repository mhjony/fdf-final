/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:03:48 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/03 12:03:55 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a fresh string ending with \0, result of the
** concatenation of s1 and s2. It creates a fresh string in ft_strnew.
** With ft_strlen it determines the length of the string of both strings
** With ft_strcpy, the s1 will be copied into res and in ft_strcat the s2
** will be appended to res.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (res == NULL)
	{
		return (NULL);
	}
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}
