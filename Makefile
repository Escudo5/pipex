NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -Icustom-libft

SRCS = main.c forks.c path.c utils.c

SRCS_BONUS = 


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = custom-libft
LIBFT = $(LIBFT_DIR) /libft.a


all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
		$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) | $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME) $(NAME_BONUS)
re: fclean all

:PHONY: clean fclean re all bonus