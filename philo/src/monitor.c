/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:19:10 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 02:20:38 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_pdata	*pdata;
	
	pdata = (t_pdata *)arg;
	(void)pdata;
	return (NULL);
}

int	check_alive(t_philo *philo)
{
	(void)philo;
	return (1);
}

void	philo_died(t_philo *philo)
{
	printf("%lld %d died\n", get_time_current() - philo->pdata1->start_time, philo->id + 1);
	(void)philo;
	return ;
}
