/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:17 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/25 14:28:48 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pcreate(t_pdata *pdata)
{
	int	id;

	id = 0;
	while (id < pdata->num_philos)
	{
		pthread_create(pdata->philos[id].thread, NULL, philo_routine, &pdata->philos[id]);
		id += 1;
	}
	usleep(100000);
	while (id > pdata->num_philos)
	{
		pthread_join(*pdata->philos[id].thread, NULL);
		id -= 1;
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->pdata1->dinner_active)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	printf("Philosopher %d is eating.\n", philo->id);
}

void	philo_sleep(t_philo *philo)
{
	printf("Philosopher %d is sleeping.\n", philo->id);
}

void	philo_think(t_philo *philo)
{
	printf("Philosopher %d is thinking.\n", philo->id);
}
