/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:47 by julian            #+#    #+#             */
/*   Updated: 2024/07/30 16:49:29 by jmuhlber         ###   ########.fr       */
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

int	get_num_times_eat(t_pdata *pdata)
{
	int	ret;

	pthread_mutex_lock(&pdata->protect->num_times_eat);
	ret = pdata->num_times_eat;
	pthread_mutex_unlock(&pdata->protect->num_times_eat);
	return (ret);
}

int	gs_dinner_active(t_pdata *pdata, int mode, int val)
{
	int	ret;

	pthread_mutex_lock(&pdata->protect->active);
	if (mode)
	{
		pdata->dinner_active = val;
		pthread_mutex_unlock(&pdata->protect->active);
		return (val);
	}
	else
	{
		ret = pdata->dinner_active;
		pthread_mutex_unlock(&pdata->protect->active);
		return (ret);
	}
}

unsigned long	get_start_time(t_pdata *pdata)
{
	unsigned long	ret;

	pthread_mutex_lock(&pdata->protect->start_time);
	ret = pdata->start_time;
	pthread_mutex_unlock(&pdata->protect->start_time);
	return (ret);
}
