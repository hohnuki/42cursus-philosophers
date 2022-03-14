#include "../includes/philo.h"

static void	free_double_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all_elem(t_info *info)
{
	if (info->philos != NULL)
		free (info->philos);
	if (info->monitors != NULL)
		free (info->monitors);
	if (info->forks_mutex != NULL)
		free_double_array((void **)info->forks_mutex);
}