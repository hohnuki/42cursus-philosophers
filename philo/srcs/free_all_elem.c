#include "../includes/philo.h"

void	free_all_elem(t_info *info)
{
	if (info->philos != NULL)
		free (info->philos);
	if (info->monitors != NULL)
		free (info->monitors);
}