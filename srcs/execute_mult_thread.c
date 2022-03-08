#include "../includes/philo.h"

void	print_message(t_mutex *array)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	printf("%.13d %d has taken a fork\n", tv.tv_usec, array->index);
}

void *f(void *ptr)
{
	print_message(ptr);
	return (NULL);
}

void	execute_mult_thread(t_info *info)
{
	int	i;

	info->array = malloc(sizeof(t_mutex) * info->argc);
	if (info->array == NULL)
		free_element(info);
	i = 0;
	while (i < info->num_of_philosophers)
	{
		info->array[i].fork_count = 0;
		info->array[i].index = i;
		pthread_mutex_init(&(info->array[i].mutex), NULL);
		pthread_create(&(info->array[i].thread), NULL, &f, &(info->array[i]));
		pthread_join(info->array[i].thread, NULL);
		i++;
	}
}