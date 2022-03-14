#include "../includes/philo.h"

size_t	get_time(t_info *info)
{
	struct timeval	tv;
	size_t			time;
	int				ret;

	ret = gettimeofday(&tv, NULL);
	if (ret == -1)
		free_all_elem(info);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}