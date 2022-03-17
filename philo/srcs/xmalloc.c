#include "../includes/philo.h"

void	*xmalloc(t_info *info, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		printf("\x1b[36m[eeeeeeee]\n\033[m");
		free_all_elem(info);
	}
	return (ptr);
}