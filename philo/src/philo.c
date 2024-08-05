/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:27 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/08/05 16:50:04 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_exit(t_pdata *pdata);
static void	philo_1(t_pdata *ph);

int	main(int argc, char **argv)
{
	t_pdata	*pdata;

	if (argc != 5 && argc != 6)
		return (philo_abort(1, "Wrong argument count!", NULL));
	pdata = parse_args(argc, argv);
	if (!pdata)
		return (1);
	if (!init_philo(pdata))
		return (philo_abort(1, NULL, pdata));
	if (pdata->num_times_eat > 0 || pdata->num_times_eat == -1)
	{
		if (pdata->num_philos == 1)
			philo_1(pdata);
		else
			pcreate(pdata);
	}
	if (pdata)
		philo_exit(pdata);
	return (0);
}

/**
 * Aborts the philosopher program based on an error condition.
 * 
 * @param is_err Indicator if an error occurred.
 * @param err_msg Optional error message to display if an error occurred.
 * @param pdata Pointer to dynamically allocated data that should be freed.
 * @return Returns 1 if an error message was printed, otherwise returns 0.
 */
int	philo_abort(u_int8_t is_err, char *err_msg, t_pdata *pdata)
{
	if (pdata)
		free(pdata);
	if (is_err)
	{
		if (err_msg != NULL)
			printf("Error: %s\n", err_msg);
		else
			printf("Error! Undefined error.\n");
		return (1);
	}
	return (0);
}

/**
 * Cleans up and exits the philosopher program by destroying mutexes and
 * freeing allocated memory.
 * 
 * @param pdata Pointer to the program data structure containing philosophers,
 * forks, and protection structures.
 * @return Always returns 1 after cleanup is complete.
 */
static int	philo_exit(t_pdata *pdata)
{
	int	id;

	id = 0;
	while (id < pdata->num_philos)
	{
		pthread_mutex_destroy(&pdata->philos[id].nte_lock);
		pthread_mutex_destroy(&pdata->philos[id].tle_lock);
		pthread_mutex_destroy(&pdata->forks[id]);
		id += 1;
	}
	pthread_mutex_destroy(&pdata->protect->active);
	pthread_mutex_destroy(&pdata->protect->output);
	free(pdata->philos);
	free(pdata->protect);
	free(pdata->forks);
	free(pdata);
	return (1);
}

/**
 * Just one philosopher.
 * 
 * @param ph Pointer to the program data structure.
 */
static void	philo_1(t_pdata *ph)
{
	ph->start_time = get_time_current();
	output_status(&ph->philos[0], FORK);
	philo_wait(ph->time_2_die);
	output_status(&ph->philos[0], DIED);
}
