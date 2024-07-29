/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:18 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/29 05:11:54 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int			init_forks(t_pdata *pdata);
static t_protect	*init_protect(void);

int	init_philo(t_pdata *pdata)
{
	int	id;

	id = 0;
	
	pdata->dinner_active = 1;
	pdata->philos = malloc(sizeof(t_philo) * pdata->num_philos + 1);
	if (!pdata->philos || !init_forks(pdata))
		return (0);
	pdata->protect = init_protect();
	if (!pdata->protect)
		return (0);
	while (id < pdata->num_philos)
	{
		pdata->philos[id].id = id;
		pdata->philos[id].num_times_eaten = 0;
		pdata->philos[id].time_last_eat = 0;
		pdata->philos[id].pdata1 = pdata;
		pdata->philos[id].protect = pdata->protect;
		
		pdata->philos[id].fork_2t_left = &pdata->forks[id];
		pthread_mutex_init(pdata->philos[id].fork_2t_left, NULL);
		
		pdata->philos[id].fork_2t_right = &pdata->forks[(id + 1) % pdata->num_philos];
		pthread_mutex_init(pdata->philos[id].fork_2t_right, NULL);
		id += 1;
	}
	return (1);
}

static int	init_forks(t_pdata *pdata)
{
	int	i;

	i = 0;
	pdata->forks = malloc(sizeof(pthread_mutex_t) * pdata->num_philos + 1);
	if (!pdata->forks)
		return (0);
	while (i < pdata->num_philos)
	{
		pthread_mutex_init(&pdata->forks[i], NULL);
		i += 1;
	}
	return (1);
}

static t_protect	*init_protect(void)
{
	t_protect	*protect;

	protect = malloc(sizeof(t_protect) + 1);
	if (!protect)
		return (NULL);
	pthread_mutex_init(&protect->active, NULL);
	return (protect);
}
