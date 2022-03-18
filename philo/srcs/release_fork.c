/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:39 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:40:40 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	release_fork(t_philo *philo)
{
	size_t	fork_index;

	fork_index = philo->philo_number;
	printf("\x1b[36m[%s philo_num %zu]\n\033[m", "release_fork in", philo->philo_number);
	if (philo->has_fork_left == true && philo->has_fork_right == true)
	{
		pthread_mutex_unlock(&(philo->info->forks_mutex[fork_index]));
		philo->has_fork_left = false;
		philo->has_fork_right = false;
		sleep_philo(philo);
	}
}