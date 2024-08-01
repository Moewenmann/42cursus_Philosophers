/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:38 by julian            #+#    #+#             */
/*   Updated: 2024/08/01 13:35:34 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Gets the time to die value from the program data structure.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The time to die value.
 */
size_t	get_time_2_die(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_die);
	ret = pdata->time_2_die;
	pthread_mutex_unlock(&pdata->protect->time_2_die);
	return (ret);
}

/**
 * Gets the time to eat value from the program data structure.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The time to eat value.
 */
size_t	get_time_2_eat(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_eat);
	ret = pdata->time_2_eat;
	pthread_mutex_unlock(&pdata->protect->time_2_eat);
	return (ret);
}

/**
 * Gets the time to sleep value from the program data structure.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The time to sleep value.
 */
size_t	get_time_2_sleep(t_pdata *pdata)
{
	size_t	ret;

	pthread_mutex_lock(&pdata->protect->time_2_sleep);
	ret = pdata->time_2_sleep;
	pthread_mutex_unlock(&pdata->protect->time_2_sleep);
	return (ret);
}

/**
 * Gets the number of philosophers from the program data structure.
 * 
 * @param pdata Pointer to the program data structure.
 * @return The number of philosophers.
 */
int	get_num_philos(t_pdata *pdata)
{
	int	ret;

	pthread_mutex_lock(&pdata->protect->num_philos);
	ret = pdata->num_philos;
	pthread_mutex_unlock(&pdata->protect->num_philos);
	return (ret);
}
