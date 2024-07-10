/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:50:45 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/10 13:59:07 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_input_data(t_philo *philo);
static int	check_argv_is_int(char **argv);

t_philo	*parse_args(int argc, char **argv)
{
	t_philo	*philo;

	(void)argc;
	if (!check_argv_is_int(argv))
		return (philo_abort(1, "Invalid argument(s).", NULL), NULL);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (philo_abort(1, "Malloc fail.", NULL), NULL);
	philo->num_philos = phl_atoi(argv[1]);
	philo->time_2_die = phl_atoi(argv[2]);
	philo->time_2_eat = phl_atoi(argv[3]);
	philo->time_2_sleep = phl_atoi(argv[4]);
	if (argv[5])
		philo->num_times_eat = phl_atoi(argv[5]);
	else
		philo->num_times_eat = -1;
	if (check_input_data(philo))
		return (NULL);
	return (philo);
}

static int	check_input_data(t_philo *philo)
{
	if (philo->num_philos < 2)
		return (philo_abort(1, "Number of Philosophers must be at least 2.",
				philo));
	if (philo->num_philos > 200 && PHILO_LIMIT_200)
		return (philo_abort(1, "Number of Philosophers must be at most 200.",
				philo));
	if (philo->time_2_die < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to die must be at least 60ms.", philo));
	if (philo->time_2_eat < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to eat must be at least 60ms.", philo));
	if (philo->time_2_sleep < 60 && TIME_LIMIT_60)
		return (philo_abort(1, "Time to sleep must be at least 60ms.", philo));
	if (philo->num_times_eat < (size_t)-1)
		return (philo_abort(1, "Invalid number of times to eat.", philo));
	if (philo->time_2_die <= 0 || philo->time_2_eat <= 0
		|| philo->time_2_sleep <= 0)
		return (philo_abort(1, "Time values must be greater than 0.", philo));
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
