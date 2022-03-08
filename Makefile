CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
INCLUDES = includes
SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)main.c $(SRCS_PATH)philo_atoi.c $(SRCS_PATH)free.c \
		$(SRCS_PATH)error_message.c
OBJS = $(SRCS:.c=.o)

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