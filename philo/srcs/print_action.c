/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:37 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:40:38 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo *philo, char *message)
{
//	pthread_mutex_lock(&(philo->info->shared_mutex));
	printf("%zu %zu %s\n", get_time(philo->info), philo->philo_number, message);
//	pthread_mutex_unlock(&(philo->info->shared_mutex));
}