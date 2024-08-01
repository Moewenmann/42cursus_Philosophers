/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:55 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/08/01 13:24:13 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Gets the current time in milliseconds.
 * 
 * @return The current time in milliseconds.
 */
unsigned long	get_time_current(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * Logs the time elapsed since the start of the simulation.
 * 
 * @param pdata Pointer to the program data structure
 * containing the start time.
 * @return The elapsed time in milliseconds since the start of the simulation.
 */
unsigned long	log_time(t_pdata *pdata)
{
	return (get_time_current() - get_start_time(pdata));
}

/**
 * Makes the calling thread wait for the specified amount of time.
 * 
 * @param sleep_time The time to sleep in milliseconds.
 */
void	philo_wait(unsigned long sleep_time)
{
	unsigned long	start;

	start = get_time_current();
	if (start <= 0 || start <= sleep_time)
		return ;
	while (get_time_current() - start < sleep_time)
		usleep(TICK);
}
