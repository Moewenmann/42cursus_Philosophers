/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:17 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/28 18:13:20 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pcreate(t_pdata *pdata)
{
	int	id;

	id = 0;
	while (id < pdata->num_philos)
	{
		pthread_create(&pdata->philos[id].thread, NULL, philo_routine, &pdata->philos[id]);
		id += 1;
	}
	while (id >= 0)
	{
		pthread_join(pdata->philos[id].thread, NULL);
		id -= 1;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
	{
		while (philo->pdata1->dinner_active)
		{
			philo_sleep(philo);
			philo_think(philo);
			philo_eat(philo);
		}
	}
	else
	{
		while (philo->pdata1->dinner_active)
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_2t_left);
	pthread_mutex_lock(philo->fork_2t_right);
	philo->time_last_eat = get_time_current();
	printf("Philosopher %d is eating.\n", philo->id);
	philo_wait(philo->pdata1->time_2_eat);
	philo->num_times_eaten += 1;
	pthread_mutex_unlock(philo->fork_2t_left);
	pthread_mutex_unlock(philo->fork_2t_right);
}

void	philo_sleep(t_philo *philo)
{
	printf("Philosopher %d is sleeping.\n", philo->id);
	philo_wait(philo->pdata1->time_2_sleep);
}

void	philo_think(t_philo *philo)
{
	printf("Philosopher %d is thinking.\n", philo->id);
}
