/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:31:17 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/29 02:40:44 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pcreate(t_pdata *pdata)
{
	int	id;

	id = 0;
	pthread_create(&pdata->monitor, NULL, monitor, pdata);
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
	pthread_join(pdata->monitor, NULL);
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
	if (!check_alive(philo))
		return (philo_died(philo));
	pthread_mutex_lock(philo->fork_2t_left);
	printf("%lu %d has taken a LEFT fork.\n", log_time(philo->pdata1), philo->id);
	if (!check_alive(philo))
		return (philo_died(philo));
	pthread_mutex_lock(philo->fork_2t_right);
	printf("%lu %d has taken a RIGHT fork.\n", log_time(philo->pdata1), philo->id);
	if (!check_alive(philo))
		return (philo_died(philo));
	philo->time_last_eat = get_time_current();
	printf("%lu %d is eating.\n", log_time(philo->pdata1), philo->id);
	philo_wait(philo->pdata1->time_2_eat);
	philo->num_times_eaten += 1;
	pthread_mutex_unlock(philo->fork_2t_left);
	pthread_mutex_unlock(philo->fork_2t_right);
	printf("%lu %d droped forks\n", log_time(philo->pdata1), philo->id);
}

void	philo_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping.\n", log_time(philo->pdata1), philo->id);
	philo_wait(philo->pdata1->time_2_sleep);
}

void	philo_think(t_philo *philo)
{
	printf("%lu %d is thinking.\n", log_time(philo->pdata1), philo->id);
}
