/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:35 by jmuhlber          #+#    #+#             */
/*   Updated: 2024/08/01 14:02:24 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//_--------------------------------------------------------------------------_//
// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>

//_--------------------------------------------------------------------------_//
// ** ----------------------------- STRUCTS ----------------------------- ** //

typedef struct s_philo		t_philo;
typedef struct s_pdata		t_pdata;
typedef struct s_protect	t_protect;

struct s_philo
{
	int				id;
	size_t			num_times_eaten;
	pthread_mutex_t	nte_lock;
	unsigned long	time_last_eat;
	pthread_mutex_t	tle_lock;
	pthread_mutex_t	*fork_2t_left;
	pthread_mutex_t	*fork_2t_right;
	pthread_t		thread;
	t_protect		*protect;
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
	t_protect		*protect;
	t_philo			*philos;
};

struct s_protect
{
	pthread_mutex_t	active;
	pthread_mutex_t	start_time;
	pthread_mutex_t	time_2_die;
	pthread_mutex_t	time_2_eat;
	pthread_mutex_t	time_2_sleep;
	pthread_mutex_t	num_times_eat;
	pthread_mutex_t	num_philos;
	pthread_mutex_t	output;
};

//_--------------------------------------------------------------------------_//
// ** ---------------------------- FUNCTIONS ---------------------------- ** //

t_pdata			*parse_args(int argc, char **argv);
int				philo_abort(u_int8_t is_err, char *err_msg, t_pdata *pdata);
int				init_philo(t_pdata *pdata);

//utils
int				phl_atoi(const char *str);
int				phl_isdigit(int c);
int				phl_strncmp(const char *s1, const char *s2, size_t n);
size_t			phl_strlen(const char *c);

//time
unsigned long	get_time_current(void);
unsigned long	log_time(t_pdata *pdata);
void			philo_wait(unsigned long sleep_time);

//routines
void			pcreate(t_pdata *pdata);
void			*philo_routine(void *arg);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

//monitor
void			*monitor(void *arg);
void			output_status(t_philo *philo, const int status);
int				check_alive(t_philo *philo);
void			philo_died(t_philo *philo);

//get-set -> pdata
size_t			get_time_2_die(t_pdata *pdata);
size_t			get_time_2_eat(t_pdata *pdata);
size_t			get_time_2_sleep(t_pdata *pdata);
int				get_num_philos(t_pdata *pdata);
int				get_num_times_eat(t_pdata *pdata);
int				gs_dinner_active(t_pdata *pdata, int mode, int val);
unsigned long	get_start_time(t_pdata *pdata);

//get-set -> philo
unsigned long	gs_time_last_eat(t_philo *philo, int mode, unsigned long val);
size_t			gs_num_times_eaten(t_philo *philo, int mode, size_t val);

//_--------------------------------------------------------------------------_//
// ** ----------------------------- MACROS ------------------------------ ** //

//philo limits
# ifndef PHILO_LIMIT_200
#  define PHILO_LIMIT_200 1
# endif

# ifndef TIME_LIMIT_60
#  define TIME_LIMIT_60 1
# endif

# ifndef TICK
#  define TICK 100
# endif

//philo get-set modes
# define GET 0
# define SET 1
# define ADD 2

//philo status codes
# define DIED 0
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4

#endif