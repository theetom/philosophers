/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:45:41 by toferrei          #+#    #+#             */
/*   Updated: 2024/12/04 15:48:02 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include "../Ft_Printf/ft_printf.h"
# include "../Libft/libft.h"

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

# define DEBUG_MODE	0

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}				t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}				t_time_code;

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		time_to_die;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}				t_philo;

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_sleep;
	long		time_to_eat;
	long		nbr_limits_meals;
	long		start_simulation;
	bool		end_simulation;
	bool		all_threads_ready;
	long		threads_running_nbr;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
};

void	dinner_start(t_table *table);
void	thinking(t_philo *philo, bool pre_simulation);

// Parsing

void	parse_input(t_table *table, char **argv);

// Utils

void	error_exit(const char *error);
long	get_time(t_time_code time_code);
void	precise_usleep(long usec, t_table *table);
void	clean(t_table *table);

// Init

void	data_init(t_table *table);

// Safe Functions

void	*safe_malloc(size_t bytes);
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);

// getter_setter

void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	simulation_finished(t_table *table);

// Synchro Utils

void	wait_all_threads(t_table *table);
bool	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr);
void	increase_long(t_mtx *mutex, long *value);
void	de_synchronizing_philos(t_philo *philo);

// Write

void	write_status(t_philo_status status, t_philo *philo, bool debug);

// Monitoring

void	*monitor_dinner(void *data);

#endif