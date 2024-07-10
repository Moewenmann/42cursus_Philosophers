/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:27 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/10 13:23:50 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (philo_abort(1, "Wrong argument count!\n", NULL));
	philo = parse_args(argc, argv);
	if (!philo)
		return (1);
	if (philo)
		free(philo);
	return (0);
}

int	philo_abort(u_int8_t is_err, char *err_msg, t_philo *philo)
{
	free(philo);
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
