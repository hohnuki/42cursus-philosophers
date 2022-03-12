#include "../includes/philo.h"

static void	pick_up_fork(t_info *info)
{
	if (info->fork_status[info->current_index] == true)
	{
		printf("%zu %d has taken a fork\n", print_time(info), info->current_index);
		info->fork_status[info->current_index] = false;
		info->array[info->current_index].fork_count++;
	}
	if (info->fork_status[info->current_index + 1] == true)
	{
		printf("%zu %d has taken a fork\n", print_time(info), info->current_index);
		info->fork_status[info->current_index + 1] = false;
		info->array[info->current_index].fork_count++;
	}
	if (info->array[info->current_index].fork_count == 2)
	{
		printf("%zu %d is eating\n", print_time(info), info->current_index);
		info->array[info->current_index].fork_count = 0;
		usleep(info->time_to_eat);
	}
}

void	print_message(t_info *info)
{
	while (1)
	{
		if (info->array[info->current_index].fork_count < 2)
		{
			pthread_mutex_lock(&(info->array[info->current_index].mutex));
			pick_up_fork(info);
			pthread_mutex_unlock(&(info->array[info->current_index].mutex));
		}
	}
}

static void	*f(void *ptr)
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
		info->current_index = i + 1;
		pthread_mutex_init(&(info->array[i].mutex), NULL);
		pthread_create(&(info->array[i].thread), NULL, &f, info);
		pthread_join(info->array[i].thread, NULL);
		i++;
	}
}