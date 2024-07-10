/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuhlber <jmuhlber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:35 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/10 14:32:44 by jmuhlber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

# ifndef PHILO_LIMIT_200
#  define PHILO_LIMIT_200 1
# endif

# ifndef TIME_LIMIT_60
#  define TIME_LIMIT_60 1
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
	pthread_t		*thread;
}				t_philo;

typedef struct s_pdata
{
	t_philo		*philos;
}				t_pdata;

t_philo	*parse_args(int argc, char **argv);
int		philo_abort(u_int8_t is_err, char *err_msg, t_philo *philo);

//utils
int		phl_atoi(const char *str);
int		phl_isdigit(int c);
int		phl_strncmp(const char *s1, const char *s2, size_t n);
size_t	phl_strlen(const char *c);

#endif