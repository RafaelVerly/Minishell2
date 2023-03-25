NAME 			= minishell
LIBFT			= libft.a

LIBFT_PATH 		= ./libft/

#compilation
CC 				= cc -g
CF 				= -Wall -Wextra -Werror
LIBS			= -lreadline

SRC 			=	teste.c \
					dup_linked_list.c \
					dup_array.c \
					execv_teste.c

#common commands
RM 				= rm -rf

#rules
$(NAME):	$(SRC) $(LIBFT_PATH)
				make -C $(LIBFT_PATH) $(LIBFT)
				$(CC) $(CF) $(SRC) -o $(NAME) -L $(LIBFT_PATH) -lft $(LIBS)

all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

.PHONY:			all clean fclean re