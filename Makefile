# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 21:40:24 by tamatsuu          #+#    #+#              #
#    Updated: 2024/08/29 04:14:17 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
#CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror 
SRCS		= ./src/main.c \
./src/utils.c \
./src/validate.c \
./src/validation_utils.c \
./src/push_swap.c \
./src/push_swap_utils.c \
./src/push_swap_utils_2.c \
./src/move.c \
./src/ope_info_utils.c \
./src/sort.c \
./src/stack_a_operation.c \
./src/stack_b_operation.c \
./src/listutils.c


OBJS		= $(SRCS:%.c=%.o)
BONUS		=
LIB			= ./libft/libft.a
BOBJS		= $(BONUS:%.c=%.o)
NAME		= push_swap
AR		= ar

.PHONY: all clean fclean re norm bonus
.SILENT: all
all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft 
	$(CC) $(OBJS) -Lft -lft -L./libft -o $(NAME)



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(OBJS) $(BOBJS)
	
fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

#bonus: $(BOBJS)
#	@make -C libft
#	@cp $(LIB) $(NAME)
#	$(AR) rcs $(NAME) $(BOBJS)

#$(BOBJS): $(BONUS)
#	$(CC) $(CFLAGS) -c $(BONUS)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine *.h

re: fclean all
