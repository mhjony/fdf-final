# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhasan <mhasan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:52:45 by ismelich          #+#    #+#              #
#    Updated: 2020/02/13 20:58:44 by mhasan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBDIR = libft/
HEADERDIR = libft/

HEADER = fdf.h

LIB = $(LIBDIR)libft.a

SRC = main.c read_file.c draw_hub.c color.c controls_iso.c

OBJ = $(SRC:.c=.o)

MLX_LINK = /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIB) -I $(HEADERDIR) -L $(MLX_LINK)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all