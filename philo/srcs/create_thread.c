/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:13 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:40:14 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_thread(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		pthread_create(&(info->philos[i]->thread_philo), NULL, philo_func, info->philos[i]);
		pthread_create(&(info->monitors[i]->thread_monitor), NULL, monitor_func, info->monitors[i]);
		i++;
	}
}