/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_pdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:38 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 15:22:59 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time_2_die(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_die);
	ret = pdata->time_2_die;
	pthread_mutex_unlock(&pdata->protect->time_2_die);
	return (ret);
}

size_t	get_time_2_eat(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_eat);
	ret = pdata->time_2_eat;
	pthread_mutex_unlock(&pdata->protect->time_2_eat);
	return (ret);
}

size_t	get_time_2_sleep(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_sleep);
	ret = pdata->time_2_sleep;
	pthread_mutex_unlock(&pdata->protect->time_2_sleep);
	return (ret);
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
