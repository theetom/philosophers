/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:34:29 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/21 16:17:05 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

		// sleep
		thingking(philo);
		
	}
	
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int i;

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
	table->start_simulation = get_time(MILISECOND);

	
	set_bool(&table->table_mutex, &table->all_threads_ready, true);

	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	
}
