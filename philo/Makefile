# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julian <julian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 11:06:29 by julian            #+#    #+#              #
#    Updated: 2024/08/01 03:01:11 by julian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -I inc -g

OBJDIR	= obj

VPATH	= inc \
			src \

SRC		= philo.c \
			parse.c \
			init.c \
			routines.c \
			monitor.c \
			time.c \
			var_a.c \
			var_b.c \
			util.c

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	echo "philo compiled."

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean:
	make clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
