#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "sys/time.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
# include "pthread.h"
# include "limits.h"

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	pthread_t		thread;
	int				fork_count;
}	t_mutex;

typedef struct s_info
{
	int		argc;
	char 	**argv;
	int		num_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	t_mutex	*array;
	int		current_index;
	bool	*fork_status;
}	t_info;

//philo_atoi.c
int	philo_atoi(const char *str, t_info *info);
int	ft_isdigit(int c);

//execute_mult_thread.c
void	execute_mult_thread(t_info *info);

//error_message.c
void	error_message(t_info *info);

//free.c
void	free_element(t_info *info);

#endif