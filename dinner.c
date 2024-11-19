/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:34:29 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/19 15:44:22 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;

	wait_all_threads(philo->table);
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
	table->start_simulation

	
	set_bool(&table->table_mutex, &table->all_threads_ready, true)
}
