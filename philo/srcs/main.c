#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	init_structure(&info, argc, argv);
	create_thread(&info);
}