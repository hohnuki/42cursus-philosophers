/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:04 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:39:05 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_time(t_info *info)
{
	struct timeval	tv;
	size_t			time;
	int				ret;

	ret = gettimeofday(&tv, NULL);
	if (ret == -1)
		free_all_elem(info);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}