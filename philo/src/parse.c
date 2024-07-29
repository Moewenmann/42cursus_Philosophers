/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:45 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/29 16:50:34 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_input_data(t_pdata *pdata);
static int	check_argv_is_int(char **argv);

t_pdata	*parse_args(int argc, char **argv)
{
	t_pdata	*pdata;

	(void)argc;
	if (!check_argv_is_int(argv))
		return (philo_abort(1, "Invalid argument(s).", NULL), NULL);
	pdata = malloc(sizeof(t_pdata));
	if (!pdata)
		return (philo_abort(1, "Malloc fail.", NULL), NULL);
	pdata->num_philos = phl_atoi(argv[1]);
	pdata->time_2_die = phl_atoi(argv[2]);
	pdata->time_2_eat = phl_atoi(argv[3]);
	pdata->time_2_sleep = phl_atoi(argv[4]);
	if (argv[5])
		pdata->num_times_eat = phl_atoi(argv[5]);
	else
		pdata->num_times_eat = -1;
	if (check_input_data(pdata))
		return (NULL);
	return (pdata);
}

static int	check_input_data(t_pdata *pdata)
{
	// if (pdata->num_philos < 2)
	// 	return (philo_abort(1, "Number of Philosophers must be at least 2.",
	// 			pdata));
	if (pdata->num_philos > 200 && PHILO_LIMIT_200)
		return (philo_abort(1, "Number of Philosophers must be at most 200.",
				pdata));
	if (pdata->time_2_die < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to die must be at least 60ms.", pdata));
	if (pdata->time_2_eat < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to eat must be at least 60ms.", pdata));
	if (pdata->time_2_sleep < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to sleep must be at least 60ms.", pdata));
	if (pdata->num_times_eat < -1)
		return (philo_abort(1, "Invalid number of times to eat.", pdata));
	if (pdata->time_2_die <= 0 || pdata->time_2_eat <= 0
		|| pdata->time_2_sleep <= 0)
		return (philo_abort(1, "Time values must be greater than 0.", pdata));
	if (pdata->start_time < 0)
		return (philo_abort(1, "Time observation failed.", pdata));
	return (0);
}

static int	check_argv_is_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!phl_isdigit(argv[i][j]))
				return (0);
			j += 1;
		}
		if (phl_strlen(argv[i]) > 10
			|| (phl_strlen(argv[i]) == 10
				&& phl_strncmp(argv[i], "2147483647", 10)))
			return (0);
		i += 1;
	}
	return (1);
}
