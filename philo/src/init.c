/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:18 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/25 14:28:07 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_pdata *pdata)
{
	int	id;

	id = 0;
	pdata->dinner_active = 1;
	pdata->philos = malloc(sizeof(t_philo) * pdata->num_philos + 1);
	while (id < pdata->num_philos)
	{
		pdata->philos[id].id = id;
		pdata->philos[id].num_times_eaten = 0;
		pdata->philos[id].time_last_eat = 0;
		pdata->philos[id].pdata1 = pdata;
		id += 1;
	}
	return (1);
}
