/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:17 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/25 17:34:47 by jmuhlber         ###   ########.fr       */
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
	printf("Philosopher %d is eating.\n", philo->id);
}

void	philo_sleep(t_philo *philo)
{
	long long	start_time;

	printf("Philosopher %d is sleeping.\n", philo->id);
	start_time = get_time_current();
	while (get_time_current() - start_time < (long long)philo->pdata1->time_2_sleep)
		usleep(100);
}

void	philo_think(t_philo *philo)
{
	printf("Philosopher %d is thinking.\n", philo->id);
}
