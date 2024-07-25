/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:27 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/25 17:19:55 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_1(t_pdata *ph);

int	main(int argc, char **argv)
{
	t_pdata	*pdata;

	if (argc != 5 && argc != 6)
		return (philo_abort(1, "Wrong argument count!", NULL));
	pdata = parse_args(argc, argv);
	if (!pdata || !init_philo(pdata))
		return (1);

	printf("Number of Philosophers: %d\n", pdata->num_philos);
	printf("Time to die: %zu\n", pdata->time_2_die);
	printf("Time to eat: %zu\n", pdata->time_2_eat);
	printf("Time to sleep: %zu\n", pdata->time_2_sleep);
	printf("Number of times to eat: %d\n", pdata->num_times_eat);
	printf("Start time: %lld\n", pdata->start_time);
	int i = pdata->num_philos;
	while (i)
	{
		printf("Philosopher %d\n", pdata->philos[i - 1].id);
		printf("Number of times eaten: %zu\n", pdata->philos[i - 1].num_times_eaten);
		printf("Time last ate: %zu\n", pdata->philos[i - 1].time_last_eat);
		i--;
	}
	printf("time el: %lld\n---------------------\n", (get_time_current() - pdata->start_time));

	if (pdata->num_philos == 1)
		philo_1(pdata);
	else
		pcreate(pdata);
	if (pdata)
		free(pdata);
	return (0);
}

static void	philo_1(t_pdata *ph)
{
	(void)ph;
	printf("Philosopher %d\n", 1);
}

int	philo_abort(u_int8_t is_err, char *err_msg, t_pdata *pdata)
{
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
