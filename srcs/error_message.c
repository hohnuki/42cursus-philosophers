#include "../includes/philo.h"

void	error_message(t_info *info)
{
	write(2, "Error\n", 6);
	free_element(info);
}