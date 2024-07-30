/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_pdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:38 by julian            #+#    #+#             */
/*   Updated: 2024/07/30 16:49:33 by jmuhlber         ###   ########.fr       */
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

int	get_num_philos(t_pdata *pdata)
{
	int	ret;

	pthread_mutex_lock(&pdata->protect->num_philos);
	ret = pdata->num_philos;
	pthread_mutex_unlock(&pdata->protect->num_philos);
	return (ret);
}
