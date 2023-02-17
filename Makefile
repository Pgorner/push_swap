
#	███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗
#	████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝
#	██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗
#	██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝
#	██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗
#	╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝

NAME = push_swap

CC =		cc
CFLAGS =	-Wall -Werror -Wextra
AR =		ar rcs
RM =		rm -rf

.SILENT:
			libft
			clean
			all
			$(NAME)

SRC =		valid.c						\
			push_swap.c					\
			read_input.c				\
			validsize.c					\
			ft_atol.c					\
			./utils/utils.c				\
			./utils/utils_a.c			\
			./utils/utils_b.c			\
			./utils/utils_f.c			\
			./sorting/sort.c			\
			./sorting/pusha.c			\
			./sorting/pushb.c			\
			./sorting/rotatea.c			\
			./sorting/nexthiloa.c		\
			./sorting/nexthilob.c		\
			./sorting/sort_small.c		\
			./sorting/operationsa.c		\
			./sorting/operationsb.c		\
			./sorting/check_sorted.c

OBJS =		$(SRC:.c=.o)

LIBFT =	./libft/libft.a

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@git clone https://github.com/Pgorner/libft.git
			@cd libft && make && make clean

all :		$(NAME)

clean :
			$(RM) $(OBJS)

fclean :	clean
			@$(RM) $(NAME)
			@$(RM) ./libft

re :		fclean all

libft: $(LIBFT)

.PHONY: all clean fclean re
