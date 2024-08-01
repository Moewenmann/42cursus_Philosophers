/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:19:10 by julian            #+#    #+#             */
/*   Updated: 2024/08/02 00:26:28 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*pstatus(u_int8_t status);

/**
 * Monitors the dining activity and determines when to stop.
 * 
 * @param arg Pointer to the program data structure.
 * @return NULL upon completion.
 */
void	*monitor(void *arg)
{
	int		id;
	t_pdata	*pdata;

	pdata = (t_pdata *)arg;
	while (gs_dinner_active(pdata, GET, 0))
	{
		id = 0;
		check_all_alive(pdata);
		if (get_num_times_eat(pdata) > 0)
		{
			while (id < get_num_philos(pdata))
			{
				if (gs_num_times_eaten(&pdata->philos[id], GET, 0)
					<= (size_t)get_num_times_eat(pdata))
					break ;
				id += 1;
			}
			if (id == get_num_philos(pdata))
				gs_dinner_active(pdata, SET, 0);
		}
		usleep(TICK / 2);
	}
	return (NULL);
}

/**
 * Checks if a philosopher starved.
 * 
 * @param philo Pointer to the philosopher structure.
 * @return 0 if the philosopher is dead, otherwise 1.
 */
int	check_alive(t_philo *philo)
{
	if ((log_time(philo->pdata1) - gs_time_last_eat(philo, GET, 0))
		>= get_time_2_die(philo->pdata1))
		return (0);
	return (1);
}

/**
 * Handles the situation when a philosopher dies.
 * 
 * @param philo Pointer to the philosopher structure.
 */
void	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->protect->output);
	if (gs_dinner_active(philo->pdata1, GET, 0))
		printf("%lu %d %s\n", log_time(philo->pdata1),
			philo->id + 1, pstatus(DIED));
	gs_dinner_active(philo->pdata1, SET, 0);
	pthread_mutex_unlock(&philo->protect->output);
	return ;
}

/**
 * Outputs the current status of a philosopher,
 * ensuring thread-safe access to the output.
 * 
 * @param philo Pointer to the philosopher structure.
 * @param status The status code to output.
 */
void	output_status(t_philo *philo, const int status)
{
	pthread_mutex_lock(&philo->protect->output);
	if (gs_dinner_active(philo->pdata1, GET, 0))
		printf("%lu %d %s\n", log_time(philo->pdata1),
			philo->id + 1, pstatus(status));
	pthread_mutex_unlock(&philo->protect->output);
}

static char	*pstatus(u_int8_t status)
{
	const char	*status_str[]
		= {"died",
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking"};

	return ((char *)status_str[status]);
}
