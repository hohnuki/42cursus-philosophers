/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:39:14 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/04/29 19:08:20 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5 || 6 < argc)
		ft_putendl_fd("Error\n", STDERR_FILENO);
	info = malloc(sizeof(t_info));
	if (info == NULL)
		exit(EXIT_FAILURE);
	init_structure(info, argc, argv);
	create_thread(info);
	join_thread(info);
}
