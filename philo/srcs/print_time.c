#include "../includes/philo.h"

size_t	print_time(t_info *info)
{
	struct timeval	tv;
	int				gettimeofday_return;

	gettimeofday_return = gettimeofday(&tv, NULL);
	if (gettimeofday_return == -1)
		free_element(info);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}