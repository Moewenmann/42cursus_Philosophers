/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:35 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/07/29 04:14:10 by julian           ###   ########.fr       */
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

# ifndef TICK
#  define TICK 100
# endif

typedef struct s_philo	t_philo;
typedef struct s_pdata	t_pdata;

struct s_philo
{
	int				id;
	size_t			num_times_eaten;
	unsigned long	time_last_eat;
	pthread_mutex_t	*fork_2t_left;
	pthread_mutex_t	*fork_2t_right;
	pthread_t		thread;
	t_pdata			*pdata1;
};

struct s_pdata
{
	size_t			time_2_die;
	size_t			time_2_eat;
	size_t			time_2_sleep;
	int				num_times_eat;
	unsigned long	start_time;
	int				num_philos;
	int				dinner_active;
	pthread_mutex_t	*forks;
	pthread_t		monitor;
	t_philo			*philos;
};

t_pdata	*parse_args(int argc, char **argv);
int		philo_abort(u_int8_t is_err, char *err_msg, t_pdata *pdata);
int		init_philo(t_pdata *pdata);

//utils
int		phl_atoi(const char *str);
int		phl_isdigit(int c);
int		phl_strncmp(const char *s1, const char *s2, size_t n);
size_t	phl_strlen(const char *c);

//time
unsigned long	get_time_current(void);
unsigned long	log_time(t_pdata *pdata);
void			philo_wait(unsigned long sleep_time);

//routines
void	pcreate(t_pdata *pdata);
void	*philo_routine(void *arg);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

//monitor
void	*monitor(void *arg);
int		check_alive(t_philo *philo);
void	philo_died(t_philo *philo);

#endif