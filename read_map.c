/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:42:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/04/14 01:45:55 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_open_file(char *file_name, char *buf)
{
	int		fd;
	int		length;

	//this function only executes when filename is available
	if((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);

	length = read(fd, buf, MAX_BYTES);
	close(fd);
	return (length);
}

int		ft_get_length(char *buf)
{
	int length;

	length = 0;
	while (*buf != '\n')
		++buf;
	++buf;
	while (*buf)
	{
		++length;
		++buf;
		if (*buf == '\n')
			break ;
	}
	return (length);
}

int		ft_valid_map(char *buf, int length)
{
	int i;
	int j;
	int	row_num;

	row_num = ft_atoi(buf);
	if (row_num <= 0)
		return (0);
	while (*buf != '\n')
		++buf;
	++buf;
	j = -1;
	while (*buf && ++j < row_num)
	{
		i = -1;
		while (++i < length)
		{
			if (*buf == '\n' || *buf == '\0')
				return (0);
			++buf;
		}
		++buf;
	}
	if (j >= row_num && buf != 0)
		return (0);
	return (row_num);
}

char	**ft_get_array(char *buf, int length, int row_num)
{
	int		i;
	int		j;
	char	**array;

	if (!(array = (char **)malloc(sizeof(char *) * row_num + 1)))
		return (0);
	while (*buf != '\n')
		++buf;
	++buf;
	j = -1;
	while (*buf && ++j < row_num)
	{
		i = -1;
		if (!(array[j] = (char *)malloc(sizeof(char) * length + 1)))
		{
			array[j] = 0;
			free_char_array(array);
			return (0);
		}
		while (++i < length)
			array[j][i] = *buf++;
		buf++;
		array[j][i] = 0;
	}
	array[row_num] = 0;
	return (array);
}

char	**ft_read_map(char *buf, char *filename, char *charset)
{
	char	**array;
	int		length;
	int		row_num;

	if (filename)
		ft_open_file(filename, buf);
	charset = ft_map_chars(buf);
	length = ft_get_length(buf);
	row_num = ft_valid_map(buf,length);
	if (length <= 0 || row_num <= 0 || !charset)
		return (0);
	array = ft_get_array(buf, length, row_num);
	if(!array || !charset)
		return (0);
	ft_process(array, charset, length, row_num);
	return (array);
}
