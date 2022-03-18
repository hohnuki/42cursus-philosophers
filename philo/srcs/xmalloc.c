/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:40:47 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 11:41:34 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*xmalloc(t_info *info, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		free_all_elem(info);
	return (ptr);
}