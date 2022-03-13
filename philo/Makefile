CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	philo
INCLUDES	=	includes
SRCS_FILES	=	main.c philo_atoi.c free.c error_message.c \
				execute_mult_thread.c print_time.c
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