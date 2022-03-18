/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_gettimeofday.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohnukihiroki <ohnukihiroki@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:25:51 by ohnukihirok       #+#    #+#             */
/*   Updated: 2022/03/18 12:53:10 by ohnukihirok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("tv_sec = %ld tv_usec = %06d\n", tv.tv_sec, tv.tv_usec);

	sleep(2);
	printf("\x1b[36m[%s]\033[m\n", "2sec passed");

	gettimeofday(&tv, NULL);
	printf("tv_sec = %ld tv_usec = %06d\n", tv.tv_sec, tv.tv_usec);

	usleep(5);
	printf("\x1b[36m[%s]\033[m\n", "2usec passed");

	gettimeofday(&tv, NULL);
	printf("tv_sec = %ld tv_usec = %06d\n", tv.tv_sec, tv.tv_usec);

  return 0;
}