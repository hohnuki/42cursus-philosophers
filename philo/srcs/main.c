/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:14 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 13:59:08 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_structure(info, argc, argv);
	create_thread(info);
	join_thread(info);
}
