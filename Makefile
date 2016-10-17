# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2016/10/17 19:48:50 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
INC_PATH = include
SRC_PATH = src
OBJ_PATH = obj
LIBS_NAME = libft\
	libftg
SRC_NAME = fdf_exit.c\
	fdf_get_colors.c\
	fdf_callback.c\
	fdf_parse_args.c\
	fdf_parse_map.c\
	fdf_print_map.c\
	fdf_scale_img.c\
	main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIBS = $(foreach LIB, $(LIBS_NAME), $(LIB)/$(LIB).a)
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INC_PATH) $(addprefix -I ,$(addsuffix /$(INC_PATH),$(LIBS_NAME)))
CLFLAGS = -lmlx -framework OpenGL -framework AppKit $(addprefix -L ,$(LIBS_NAME)) $(addprefix -,$(subst ib,,$(LIBS_NAME)))

.PHONY: re all norme clean fclean

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(CLFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIBS):
	@printf "\e[34;4m[Making]:\e[0m %s\n" $(patsubst %/,%,$(dir $@))
	@make -C $(dir $@) all

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@printf "\e[31;4m[Cleaning]:\e[0m %s\n"
	@rm -f $(OBJ)
	@rm -rvf $(OBJ_PATH)
	@$(foreach LIB, $(LIBS_NAME), make -C $(LIB) clean;)

fclean: clean
	@rm -fv $(NAME)
	@$(foreach LIB, $(LIBS), rm -fv $(LIB);)

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)
	@$(foreach LIB, $(LIBS_NAME), make -C $(LIB) norme;)
