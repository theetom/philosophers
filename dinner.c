/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:34:29 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/25 13:50:27 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

static void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);

	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limits_meals > 0
		&& philo->meals_counter == philo->table->nbr_limits_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);

	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);

}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	// spinlock
	wait_all_threads(philo->table);

	// set last meal time

	while (!simulation_finished(philo->table))
	{
		// 1) am i full
		if (philo->full) // todo thread safe?
			break ;
		// eat
		eat(philo);

		// sleep --> write status & precise usleep
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);

		// thinking
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limits_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		; // todo do
	else
	{
		while (++i < table->philo_nbr)
			safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	}
	// monitor
	safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE);
	
	table->start_simulation = get_time(MILLISECOND);

	
	set_bool(&table->table_mutex, &table->all_threads_ready, true);

	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	
}
