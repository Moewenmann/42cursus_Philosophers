/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:02:56 by julian            #+#    #+#             */
/*   Updated: 2024/07/31 14:23:19 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_live_check(t_pdata *pdata)
{
	int		id;
	int		local;

	id = 0;
	local = get_num_philos(pdata);
	while (id < local)
	{
		if (!check_alive(&pdata->philos[id]))
			return (id);
		id += 1;
	}
	return (-1);
}
