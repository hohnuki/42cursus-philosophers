#include "../includes/philo.h"

void	*xmalloc(t_info *info, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		free_all_elem(info);
	return (ptr);
}