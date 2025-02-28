/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:17 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/08/01 13:47:58 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Creates and starts philosopher threads and a monitor thread.
 * 
 * @param pdata Pointer to the program data structure containing
 * philo and monitor information.
 */
void	pcreate(t_pdata *pdata)
{
	int	id;

	id = 0;
	pdata->start_time = get_time_current();
	pthread_create(&pdata->monitor, NULL, monitor, pdata);
	while (id < get_num_philos(pdata))
	{
		pthread_create(&pdata->philos[id].thread,
			NULL, philo_routine, &pdata->philos[id]);
		id += 1;
	}
	id -= 1;
	while (id >= 0)
	{
		pthread_join(pdata->philos[id].thread, NULL);
		id -= 1;
	}
	pthread_join(pdata->monitor, NULL);
}

/**
 * Routine executed by each philosopher thread.
 * 
 * @param arg Pointer to the philosopher structure.
 * @return NULL upon completion.
 */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_think(philo);
	if (philo->id % 2)
	{
		philo_wait(get_time_2_eat(philo->pdata1));
	}
	while (gs_dinner_active(philo->pdata1, GET, 0))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/**
 * Simulates a philosopher eating.
 * 
 * @param philo Pointer to the philosopher structure.
 */
void	philo_eat(t_philo *philo)
{
	if (!check_alive(philo))
		return (philo_died(philo));
	pthread_mutex_lock(philo->fork_2t_left);
	output_status(philo, FORK);
	if (!check_alive(philo))
	{
		pthread_mutex_unlock(philo->fork_2t_left);
		return (philo_died(philo));
	}
	pthread_mutex_lock(philo->fork_2t_right);
	if (!check_alive(philo))
	{
		pthread_mutex_unlock(philo->fork_2t_left);
		pthread_mutex_unlock(philo->fork_2t_right);
		return (philo_died(philo));
	}
	output_status(philo, FORK);
	gs_time_last_eat(philo, SET, log_time(philo->pdata1));
	output_status(philo, EAT);
	gs_num_times_eaten(philo, ADD, 1);
	philo_wait(get_time_2_eat(philo->pdata1));
	pthread_mutex_unlock(philo->fork_2t_left);
	pthread_mutex_unlock(philo->fork_2t_right);
}

/**
 * Simulates a philosopher sleeping.
 * 
 * @param philo Pointer to the philosopher structure.
 */
void	philo_sleep(t_philo *philo)
{
	output_status(philo, SLEEP);
	philo_wait(get_time_2_sleep(philo->pdata1));
}

/**
 * Simulates a philosopher thinking.
 * 
 * @param philo Pointer to the philosopher structure.
 */
void	philo_think(t_philo *philo)
{
	output_status(philo, THINK);
}
