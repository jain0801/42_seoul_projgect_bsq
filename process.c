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
	int	m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

void	find_bsq(int **array, int length, int row_num)
{
	int	row;
	int	col;

	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (row > 0 && col > 0)
			{
				if (array[row][col] != 0 && array[row-1][col] != 0 &&
						array[row-1][col-1] != 0 && array[row][col-1] != 0)
					array[row][col] = find_min(array[row - 1][col], array[row - 1][col - 1], array[row][col - 1]) + 1;
			}
			col++;
		}
		row++;
	}
}

int		find_maxnum_in_array(int **arr, int length, int row_num)
{
	int	row;
	int	col;
	int	maxnum;

	maxnum = 0;
	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (maxnum < arr[row][col])
				maxnum = arr[row][col];
			col++;
		}
		row++;
	}
	return (maxnum);
}

void		change_maxnum_index(int *maxnum_index, int row, int col)
{
	if (maxnum_index[0] == -1)
	{
		maxnum_index[0] = row;
		maxnum_index[1] = col;
	}
	else
	{
		if (maxnum_index[0] > row)
		{
			maxnum_index[0] = row;
			maxnum_index[1] = col;
		}
		else if (maxnum_index[0] == row && maxnum_index[1] > col)
		{
			maxnum_index[0] = row;
			maxnum_index[1] = col;
		}
	}
}

int		*check_maxnum_index(int **arr, int length, int row_num, int maxnum)
{
	int	*maxnum_index;
	int	row;
	int	col;

	maxnum_index = (int *)malloc(sizeof(int) * 2);
	maxnum_index[0] = -1;
	maxnum_index[1] = -1;
	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			if (arr[row][col] == maxnum)
			{
				change_maxnum_index(maxnum_index, row, col);
			}
			col++;
		}
		row++;
	}
	return (maxnum_index);
}

char	**make_big_square(char **array, int *maxnum_index, int maxnum, char *charset)
{
	int	row;
	int 	col;

	row = 0;
	while (row < maxnum)
	{
		col = 0;
		while (col < maxnum)
		{
			array[maxnum_index[0] - row][maxnum_index[1] - col] = charset[2];
			col++;
		}
		row++;
	}
	return (array);
}

void	print_array(char **arr, int length, int row_num)
{
	int	row;
	int	col;

	row = 0;
	while (row < row_num)
	{
		col = 0;
		while (col < length)
		{
			write(1, &arr[row][col], 1);
			col++;
		}
		write(1, "\n", 2);
		row++;
	}
}

void	ft_process(char **array, char *charset, int length, int row_num)
{
	int		**arr_int;
	int		maxnum;
	int		*maxnum_index;

	arr_int = ft_make_num(array, charset, length, row_num);
	find_bsq(arr_int, length, row_num);
	maxnum = find_maxnum_in_array(arr_int, length, row_num);
	maxnum_index = check_maxnum_index(arr_int, length, row_num, maxnum);
	array = make_big_square(array, maxnum_index, maxnum, charset);
	print_array(array, length, row_num);
	free_int_array(arr_int);
}
