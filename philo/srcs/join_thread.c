/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:12:52 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/21 11:12:54 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_thread(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		pthread_join(info->philos[i]->thread_philo, NULL);
		pthread_join(info->monitors[i]->thread_monitor, NULL);
		i++;
	}
}
