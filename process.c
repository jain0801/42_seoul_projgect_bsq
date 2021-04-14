/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:41:20 by jiychoi           #+#    #+#             */
/*   Updated: 2021/04/12 18:37:50 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_make_num(char **array, char *charset, int length, int row_num)
{
	int		**arr_int;
	int		i;
	int		j;

	if (!(arr_int = (int **)malloc(sizeof(int *) * row_num + 1)))
		return (0);
	j = -1;
	while (++j < row_num)
	{
		i = -1;
		if (!(arr_int[j] = (int *)malloc(sizeof(int) * length)))
		{
			arr_int[j] = 0;
			free_int_array(arr_int);
			return (0);
		}
		while (++i < length)
		{
			if (array[j][i] == charset[0])
				arr_int[j][i] = 1;
			else if (array[j][i] == charset[1])
				arr_int[j][i] = 0;
		}
	}
	arr_int[row_num] = 0;
	return (arr_int);
}

void	ft_process(char **array, char *charset, int length, int row_num)
{
	int		**arr_int;

	arr_int = ft_make_num(array, charset, length, row_num);
	// Square Finding Algorithm function goes here!
	free_int_array(arr_int);
}