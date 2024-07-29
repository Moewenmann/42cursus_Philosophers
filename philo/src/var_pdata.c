/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_pdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 05:17:38 by julian            #+#    #+#             */
/*   Updated: 2024/07/29 05:46:42 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
