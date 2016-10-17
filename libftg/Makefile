# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2016/10/17 19:45:21 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftg.a
CC = clang
INC_PATH = include
SRC_PATH = src
OBJ_PATH = obj
SRC_NAME = ft_col_from_argb.c\
	ft_get_col_grad.c\
	ft_get_iso_pt.c\
	ft_get_iso_seg.c\
	ft_pixel_put_img.c\
	ft_seg_put_img.c\
	ft_set_bg_img.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_PATH)
CLFLAGS = -lmlx -framework OpenGL -framework AppKit

.PHONY: re all norme clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@printf "\e[31;4m[Cleaning]:\e[0m %s\n"
	@rm -f $(OBJ)
	@rm -rvf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)
