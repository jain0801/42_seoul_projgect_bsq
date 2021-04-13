/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:43:55 by jiychoi           #+#    #+#             */
/*   Updated: 2021/04/12 19:00:59 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> ///////////////delete this!!!//////////

# define MAX_BYTES 10000000

int		ft_open_file(char *file_name, char *buf);
int		ft_get_length(char *buf);
int		ft_valid_map(char *buf, int length);
char	**ft_get_array(char *buf, int length, int row_num);
char	**ft_read_map(char *buf, char *filename, char *charset);

int     ft_convert_int(char *digit);
int     ft_atoi(char *str);
char	*ft_map_chars(char *str);

void	ft_putstr(char *str);

char	**ft_map_not_available();
char	**ft_map_available();
void	free_array(char **array);
void	ft_all_argvs(char **array, char *chset, int argc, char *argv[]);

#endif
