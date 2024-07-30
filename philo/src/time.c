/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:55 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/30 17:16:39 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time_current(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	log_time(t_pdata *pdata)
{
	return (get_time_current() - get_start_time(pdata));
}

void	philo_wait(unsigned long sleep_time)
{
	unsigned long	start;

	start = get_time_current();
	if (start <= 0 || start <= sleep_time)
		return ;
	while (get_time_current() - start < sleep_time)
		usleep(TICK);
}
