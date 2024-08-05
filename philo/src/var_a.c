/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:38 by julian            #+#    #+#             */
/*   Updated: 2024/08/05 16:33:17 by jmuhlber         ###   ########.fr       */
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

	ret = pdata->time_2_die;
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

	ret = pdata->time_2_eat;
	if (ret > get_time_2_die(pdata))
		ret = get_time_2_die(pdata);
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

	ret = pdata->time_2_sleep;
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

	ret = pdata->num_philos;
	return (ret);
}
