NAME = pipex
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(FILES:.c=.o)
FILES = pipex.c pipaux.c


all : $(NAME)
$(NAME) : $(OBJS)
	@make -C libft
	@mv libft/libft.a ./libft.a
	$(CC) $(OBJS) -fsanitize=address -g -L. -lft -o $(NAME)
clean :
	@make -C libft fclean
	@$(RM) $(OBJS)
fclean : clean
	@make -C libft fclean
	@$(RM) libft.a
	@$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re