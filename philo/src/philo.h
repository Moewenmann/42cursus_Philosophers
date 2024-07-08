/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:35 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/08 16:05:22 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef PHILO_LIMIT_200
#  define PHILO_LIMIT_200 1
# endif

typedef struct s_philo
{
	int				id;
	size_t			time_2_die;
	size_t			time_2_eat;
	size_t			time_2_sleep;
	size_t			start_time;
	size_t			num_times_eat;
	int				num_philos;
}				t_philo;

int	parse_args(int argc, char **argv, t_philo *philo);

#endif