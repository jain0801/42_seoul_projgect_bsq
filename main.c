/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:35:12 by jiychoi           #+#    #+#             */
/*   Updated: 2021/04/12 19:10:29 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_map_not_available(char *charset)
{
	char	**array;
	char	*buf;
	int		size;
	int		i;

	if (!(buf = (char *)malloc(sizeof(char) * MAX_BYTES)))
		return (0);
	i = 0;
	while ((size = read(0, &buf[i], 1)))
	{
		if (i == MAX_BYTES || size == -1)
			return (0);
		printf("%c", buf[i]);
		i++;
	}
	array = ft_read_map(buf, 0, charset);
	free(buf);
	if (!array)
		return (0);
	return (array);
}

char	**ft_map_available(char *charset, char *filename)
{
	char	**array;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * MAX_BYTES)))
		return (0);
	array = ft_read_map(buf, filename, charset);
	free(buf);
	if (!array)
		return (0);
	return (array);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_all_argvs(char **array, char *chset, int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		array = ft_map_available(chset, argv[i++]);
		if (!array)
		{
			ft_putstr("map error\n");
			continue ;
		}
		int j = 0; //erase this!
		while (array[j]) //erase this!
			printf("%s\n", array[j++]); //erase this!
		free_array(array);
		free(chset);
	}
}

int		main(int argc, char *argv[])
{
	char	**array;
	char	*charset;

	array = 0;
	charset = 0;
	if (argc == 1)
	{
		array = ft_map_not_available(charset);
		if(!array || !charset)
		{
			ft_putstr("map error\n");
			return (0);
		}
		//func to find square
		free_array(array);
		free(charset);
	}
	else
		ft_all_argvs(array, charset, argc, argv);
	return (0);
}
