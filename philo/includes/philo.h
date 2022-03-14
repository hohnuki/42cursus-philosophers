#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "sys/time.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
# include "pthread.h"
# include "limits.h"

typedef struct s_philo
{
	bool	has_fork_right;
	bool	has_fork_left;
	size_t 	eat_count;
	size_t	philo_number;

	pthread_t	*thread_philo;
}	t_philo;

typedef struct s_monitor
{
	size_t	monitor_number;

	pthread_t	thread_monitor;
}	t_monitor;

typedef struct s_info
{
	int		argc;
	char	**argv;
	size_t	number_of_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_min_eat;

	t_philo			*philos;
	t_monitor		*monitors;
	pthread_mutex_t	*shared_mutex;
	pthread_mutex_t	**forks_mutex;
}	t_info;

//init.c
void	init_structure(t_info *info, int argc, char **argv);

//ft_atoi.c
int		ft_atoi(const char *str);

//xmalloc.c
void	*xmalloc(t_info *info, size_t size);

//free_all_elem.c
void	free_all_elem(t_info *info);

#endif