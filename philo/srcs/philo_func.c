/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:34 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/04/29 22:03:27 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	time_keeper(t_info *info, size_t time)
{
	size_t	start_time;
	size_t	passed_time;

	start_time = get_time(info);
	while (1)
	{
		passed_time = get_time(info);
		if (passed_time - start_time >= time)
			return ;
		usleep(100);
	}
}

void	*philo_func(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&(philo->info->shared_mutex));
//	printf("\x1b[36m[111 %zu add = %p philo_num %zu]\n\033[m", philo->info->time_to_eat, &philo->info->time_to_eat, philo->philo_number);
	philo->last_eat_time = get_time(philo->info);
	pthread_mutex_unlock(&(philo->info->shared_mutex));
	if (philo->philo_number % 2 == 1)
		usleep(200);
	while (1)
	{
		get_fork(philo->info, philo->philo_number);
		eat_philo(philo);
		sleep_philo(philo);
		release_fork(philo);
		think_philo(philo);
	}
	return (NULL);
}