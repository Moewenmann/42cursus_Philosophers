/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:19:10 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 16:02:35 by julian           ###   ########.fr       */
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
		if (get_time_2_eat(pdata) > 0)
		{
			while (id < get_num_philos(pdata))
			{
				if (gs_num_times_eaten(&pdata->philos[id], GET, 0) < (size_t)get_num_times_eat(pdata))
					break ;
				id += 1;
			}
			if (id == get_num_philos(pdata))
				gs_dinner_active(pdata, SET, 0);
		}
	}
	return (NULL);
}

int	check_alive(t_philo *philo)
{
	if ((log_time(philo->pdata1) - gs_time_last_eat(philo, GET, 0)) >= get_time_2_die(philo->pdata1))
		return (0);
	(void)philo;
	return (1);
}

void	philo_died(t_philo *philo)
{
	gs_dinner_active(philo->pdata1, SET, 0);
	printf("%lu %d died.\n", log_time(philo->pdata1), philo->id + 1);
	return ;
}
