/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:39 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 15:14:06 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	release_right_fork(t_philo *philo)
{
	size_t	fork_index;

	fork_index = philo->philo_number - 1;
	philo->has_fork_right = false;
	pthread_mutex_unlock(&(philo->info->forks_mutex[fork_index]));
}

static void	release_left_fork(t_philo *philo)
{
	size_t	fork_index;

	if (philo->philo_number == philo->info->number_of_philo)
		fork_index = 0;
	else
		fork_index = philo->philo_number - 2;
	philo->has_fork_right = false;
	pthread_mutex_unlock(&(philo->info->forks_mutex[fork_index]));
}

void	release_fork(t_philo *philo)
{
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "release_fork in", philo->philo_number);
	if (philo->has_fork_left == true && philo->has_fork_right == true)
	{
		release_left_fork(philo);
		release_right_fork(philo);
	}
}