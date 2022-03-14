CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	philo
INCLUDES	=	includes
SRCS_FILES	=	main.c ft_atoi.c free_all_elem.c create_thread.c init_structure.c \
				monitor_func.c philo_func.c xmalloc.c get_time.c print_action.c \
				release_fork.c action.c get_fork.c

SRCS		=	$(addprefix ./srcs/, $(SRCS_FILES))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME) $(SRCS_OBJS)

re : fclean all