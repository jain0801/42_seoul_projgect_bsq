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

int		find_min(int a, int b, int c)
{
	int m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	find_bsq(char **array, int length, int row_num)
{
	int row;
	int col;

	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (row > 0 && col > 0)
			{
				if (array[row][col] != 0 && arr[row-1][col] != 0 &&
						arr[row-1][col-1] != 0 && arr[row][col-1] != 0)
					arr[row][col] = min(arr[row-1][col], arr[row-1][col], arr[row-1][col]) + 1;
			}
			col++;
		}
		row++;
	}
}

int		find_maxnum_in_array(char **array, int length, int row_num)
{
	int row;
	int col;
	int maxnum;

	maxnum = 0;
	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (maxnum < arr[row][col])
				max = arr[row][col];
			col++;
		}
		row++;
	}
	return (maxnum);
}

int		check_maxnum_index(char **array, int length, int row_num, int maxnum)
{
	int maxrow;
	int maxnum_index[2];

	maxrow =

	maxnum[0] = -1;
	rownum[1] = -1;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (arr[row][col] == maxnum)
			{
				if (maxrow == -1)
				{
					maxrow = row;
					maxcol = col;
				}
				else
				{
					if (maxrow + maxcol > row + col)
					{
						maxrow = row;
						maxcol = col;
					}
				}
			}
			col++;
		}
		row++;
	}
	return (
}

void	ft_process(char **array, char *charset, int length, int row_num)
{
	int		**arr_int;

	arr_int = ft_make_num(array, charset, length, row_num);
	// Square Finding Algorithm function goes here!
	free_int_array(arr_int);
}
