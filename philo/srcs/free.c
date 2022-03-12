#include "../includes/philo.h"

void	free_element(t_info *info)
{
	if (info->array != NULL)
		free (info->array);
	if (info->fork_status != NULL)
		free (info->fork_status);
}