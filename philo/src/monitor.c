/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:19:10 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 05:39:15 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	int		id;
	t_pdata	*pdata;

	pdata = (t_pdata *)arg;
	while (gs_dinner_active(pdata, GET, 0))
	{
		id = 0;
		if (!check_alive(&pdata->philos[id]))
			philo_died(pdata->philos);
		if (pdata->num_times_eat > 0)
		{
			while (id < pdata->num_philos)
			{
				if (pdata->philos[id].num_times_eaten < (size_t)pdata->num_times_eat)
					break ;
				id += 1;
			}
			if (id == pdata->num_philos)
				gs_dinner_active(pdata, SET, 0);
		}
	}
	return (NULL);
}

int	check_alive(t_philo *philo)
{
	/* if ((log_time(philo->pdata1) - philo->time_last_eat) >= philo->pdata1->time_2_die)
		return (0); */
	(void)philo;
	return (1);
}

void	philo_died(t_philo *philo)
{
	gs_dinner_active(philo->pdata1, SET, 0);
	printf("%lu %d died.\n", log_time(philo->pdata1), philo->id + 1);
	return ;
}
