/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:20 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:40:21 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	exit(1);
}