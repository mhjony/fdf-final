/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:08:20 by mhasan            #+#    #+#             */
/*   Updated: 2020/02/03 15:59:29 by mhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words_counter(char *str)
{
	unsigned int	count;
	unsigned int	i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	if (ft_isspace(str[i]) != 1)
	{
		count++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) != 1 && ft_isspace(str[i - 1]) == 1)
			count++;
		i++;
	}
	return (count);
}
