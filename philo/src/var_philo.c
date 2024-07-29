/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:47 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 15:55:57 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	gs_time_last_eat(t_philo *philo, int mode, unsigned long val)
{
	unsigned long	ret;

	pthread_mutex_lock(&philo->tle_lock);
	if (mode)
	{
		philo->time_last_eat = val;
		pthread_mutex_unlock(&philo->tle_lock);
		return (val);
	}
	else
	{
		ret = philo->time_last_eat;
		pthread_mutex_unlock(&philo->tle_lock);
		return (ret);
	}
}

size_t	gs_num_times_eaten(t_philo *philo, int mode, size_t val)
{
	size_t	ret;

	pthread_mutex_lock(&philo->nte_lock);
	if (mode == SET)
	{
		philo->num_times_eaten = val;
		pthread_mutex_unlock(&philo->nte_lock);
		return (val);
	}
	else if (mode == ADD)
	{
		philo->num_times_eaten += val;
		ret = philo->num_times_eaten;
		pthread_mutex_unlock(&philo->nte_lock);
		return (ret);
	}
	else
	{
		ret = philo->num_times_eaten;
		pthread_mutex_unlock(&philo->nte_lock);
		return (ret);
	}
}
