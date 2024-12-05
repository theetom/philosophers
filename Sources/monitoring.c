/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:18 by toferrei          #+#    #+#             */
/*   Updated: 2024/12/05 18:01:42 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = get_time(MILLISECOND) - \
		get_long(&philo->philo_mutex, &philo->last_meal_time);
	t_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > t_to_die)
	{
		return (true);
	}
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;
	long	elapsed;
	long	start;

	table = (t_table *)data;
	
	while (!all_threads_running(&table->table_mutex,
			&table->threads_running_nbr, table->philo_nbr))
		;
	start = get_time(MILLISECOND);
	while (!simulation_finished(table))
	{
		elapsed = get_time(MILLISECOND) - table->start_simulation;
		i = -1;
		while (++i < table->philo_nbr && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				ft_printf("\n%d\n", start);
				ft_printf("\n%d\n", table->start_simulation);
				ft_printf("\n%d\n", elapsed);
				set_bool(&table->table_mutex, &table->end_simulation, true);
				write_status(DIED, table->philos + i, DEBUG_MODE, elapsed);
			}
		}
	}
	return (NULL);
}
