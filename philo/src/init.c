/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:18 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/10 14:34:58 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_pdata	*init_pdata(t_philo *philo)
{
	t_pdata	*data;

	data = malloc(sizeof(t_pdata));
	if (!data)
		return (philo_abort(1, "Malloc fail.", philo), NULL);
	data->philos = philo;
	return (data);
}
