# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 22:58:33 by mtigunit          #+#    #+#              #
#    Updated: 2023/01/03 12:54:16 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -c
NAME	= pipex
SRCS	= pipex.c utils.c
BSRCS	= bonus.c utils.c
OBJS	= $(SRCS:c=o)
BOBJS	= $(BSRCS:c=o)

%.o:%.c pipex.h
	@$(CC) $(CFLAGS) $(SRCS) $<

all: $(NAME)

$(NAME): $(OBJS)
	@echo "        Compiling...!"
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "	  -DONE-"

bonus: $(BOBJS)
	@echo "        Compiling...!"
	@$(MAKE) -C ./libft
	@$(CC) $(BOBJS) ./libft/libft.a -o pipex_bonus
	@echo "	  -DONE-"

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJS) $(BOBJS)
	@echo "OBJECT FILES CLEANED!"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME) pipex_bonus
	@echo "FILES CLEANED!"

re: fclean all