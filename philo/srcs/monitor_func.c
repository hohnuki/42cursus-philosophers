/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:32 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 18:41:18 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	die_monitor(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->shared_mutex));
	if (get_time(philo->info) - philo->last_eat_time >= philo->info->time_to_die)
	{
		pthread_mutex_unlock(&(philo->info->shared_mutex));
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->shared_mutex));
		return (false);
	}
}

void	*monitor_func(void *ptr)
{
	t_monitor	*monitors;

	monitors = (t_monitor *)ptr;
	while (1)
	{
		usleep(1000);
		if (die_monitor(monitors->philo) == true)
		{
			pthread_mutex_unlock(&(monitors->info->shared_mutex));
			print_action(monitors->philo, "died");
			exit(1);
		}
	}
	return (NULL);
}