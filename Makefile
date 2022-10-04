# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfreijo- <sfreijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 19:08:56 by sfreijo-          #+#    #+#              #
#    Updated: 2022/09/27 20:57:41 by sfreijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


 ########## ft_utils.c no se si compilara con espacio por delante ##########
 NAME = libftprintf.a

 OBJS = $(SRCS:.c=.o)

 SRCS = ft_printf.c \
 			ft_functions.c

 CC = gcc
 CFLAGS = -Wall -Wextra -Werror



all : $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)
	@echo "Compiled!"	

clean: 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re