/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:27:17 by jiychoi           #+#    #+#             */
/*   Updated: 2021/04/12 19:02:02 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_convert_int(char *digit)
{
	unsigned int number;

	number = 0;
	while (*digit)
		number = number * 10 + (*digit++ - '0');
	return (number);
}

int		ft_atoi(char *str)
{
	char	digit[100];
	char	pseudo_digit[100];
	int		index;

	index = 0;
	while (*str != '\n')
	{
		pseudo_digit[index] = *str++;
		index++;
	}
	pseudo_digit[index - 3] = 0;
	index = 0;
	while (*pseudo_digit >= '0' && *pseudo_digit <= '9')
	{
		digit[index] = pseudo_digit[index];
		index++;
	}
	digit[index] = '\0';
	return (ft_convert_int(digit));
}

char	*ft_map_chars(char *str)
{
	char	*chars;
	char	pseudo_digit[100];
	int		index;

	chars = (char *)malloc(sizeof(char) * 4);
	if (!chars)
		return (0);
	index = 0;
	while (*str != '\n')
	{
		pseudo_digit[index] = *str++;
		index++;
	}
	chars[0] = pseudo_digit[index - 3];
	chars[1] = pseudo_digit[index - 2];
	chars[2] = pseudo_digit[index - 1];
	chars[3] = 0;
	return(chars);
}
