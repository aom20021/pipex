NAME = pipex
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -crs
FILES = pipex.c commands.c info.c
SANITIZE = -fsanitize=address

all : $(NAME)

$(NAME) :
	@make -C libft
	@cp libft/libft.a .
	@$(CC) $(CFLAGS) $(SANITIZE) -L./libft -o $(NAME) $(FILES) -lft
clean :
	@make -C libft fclean
	@$(RM) $(NAME)
	@$(RM) libft.a
fclean : clean
	@make -C libft fclean
	@$(RM) $(NAME)
	@$(RM) libft.a
re : fclean all
.PHONY : all clean fclean re