/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:25:54 by julian            #+#    #+#             */
/*   Updated: 2024/08/05 17:03:20 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_all_alive(t_pdata *pdata)
{
	int		id;

	id = 0;
	while (id < get_num_philos(pdata))
	{
		if (!check_alive(&pdata->philos[id]))
		{
			philo_died(&pdata->philos[id]);
			gs_dinner_active(pdata, SET, 0);
		}
		id += 1;
	}
	return ;
}
