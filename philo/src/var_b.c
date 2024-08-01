/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:47 by julian            #+#    #+#             */
/*   Updated: 2024/08/01 13:39:26 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Gets or sets the last eating time for a philosopher.
 * 
 * @param philo Pointer to the philosopher structure.
 * @param mode If non-zero, sets the time_last_eat to val, otherwise
 * gets the current time_last_eat.
 * @param val The value to set time_last_eat to if mode is non-zero.
 * @return The last eating time if mode is zero, otherwise the new value set.
 */
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

/**
 * Gets or sets the number of times a philosopher has eaten.
 * 
 * @param philo Pointer to the philosopher structure.
 * @param mode If SET, sets num_times_eaten to val;
 * if ADD, adds val to num_times_eaten; otherwise, gets num_times_eaten.
 * @param val The value to set or add to num_times_eaten.
 * @return The current or updated number of times eaten.
 */
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

/**
 * Gets the number of times philosophers must eat.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The number of times philosophers must eat.
 */
int	get_num_times_eat(t_pdata *pdata)
{
	int	ret;

	pthread_mutex_lock(&pdata->protect->num_times_eat);
	ret = pdata->num_times_eat;
	pthread_mutex_unlock(&pdata->protect->num_times_eat);
	return (ret);
}

/**
 * Gets or sets the dinner active status.
 * 
 * @param pdata Pointer to the program data structure.
 * @param mode If non-zero, sets dinner_active to val, otherwise
 * gets the current dinner_active status.
 * @param val The value to set dinner_active to if mode is non-zero.
 * @return The current or updated dinner active status.
 */
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

/**
 * Gets the start time of the simulation.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The start time of the simulation.
 */
unsigned long	get_start_time(t_pdata *pdata)
{
	unsigned long	ret;

	pthread_mutex_lock(&pdata->protect->start_time);
	ret = pdata->start_time;
	pthread_mutex_unlock(&pdata->protect->start_time);
	return (ret);
}
