# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 04:38:21 by auverneu          #+#    #+#              #
#    Updated: 2016/10/14 13:26:08 by auverneu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Werror -Wextra
INC_PATH = include
CPPFLAGS = -I $(INC_PATH)
SRC_PATH = src
OBJ_PATH = obj
SRC_NAME = ft_abs.c\
	ft_arrjoin.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_bitlen.c\
	ft_bzero.c\
	ft_caseeq.c\
	ft_free_2d_arr.c\
	ft_gnl.c\
	ft_ilen_base.c\
	ft_ilen.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_islower.c\
	ft_ispow2.c\
	ft_isprint.c\
	ft_isspace.c\
	ft_isupper.c\
	ft_itoa_base.c\
	ft_itoa.c\
	ft_lstadd.c\
	ft_lstdel.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_match.c\
	ft_max.c\
	ft_memalloc.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memmove.c\
	ft_memset_int.c\
	ft_memset.c\
	ft_min.c\
	ft_nmatch.c\
	ft_pow.c\
	ft_putchar_fd.c\
	ft_putchar.c\
	ft_putendl_fd.c\
	ft_putendl.c\
	ft_putnbr_fd.c\
	ft_putnbr.c\
	ft_putstr_fd.c\
	ft_putstr.c\
	ft_sqrt.c\
	ft_strcasestr.c\
	ft_strcat.c\
	ft_strchr.c\
	ft_strclr.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdel.c\
	ft_strdup.c\
	ft_strequ.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strndup.c\
	ft_strnequ.c\
	ft_strnew.c\
	ft_strnlen.c\
	ft_strnrev.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strrev.c\
	ft_strrot.c\
	ft_strsplit.c\
	ft_strstr.c\
	ft_strsub.c\
	ft_strtolower.c\
	ft_strtoupper.c\
	ft_strtrim.c\
	ft_strxjoin.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_wclen.c\
	ft_wcslen.c\
	ft_wcsstrlen.c\
	ft_wctomb.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: re all norme printcomp clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\e[32;4m[Linking]:\e[0m %s\n" $@
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH) printcomp
	@printf "%s\n" $@
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

printcomp:
	@printf "\e[36;4m[Compiling]:\e[0m\n"

clean:
	@printf "\e[35;4m[Cleaning]:\e[0m\n"
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@printf "\e[31;4m[Cleaning]:\e[0m\n"
	@rm -fv $(NAME)

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)
