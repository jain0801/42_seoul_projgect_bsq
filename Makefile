# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 11:39:59 by jiychoi           #+#    #+#              #
#    Updated: 2021/04/12 11:42:34 by jiychoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
PARAM = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = bsq

all : $(TARGET)

%.o : %.c
	$(CC) $(PARAM) -c -o $@ $< -I ./

$(TARGET) : $(OBJ)
	$(CC) $(PARAM) -o $@ $^

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

