/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:04:47 by toferrei          #+#    #+#             */
/*   Updated: 2024/12/04 15:47:42 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	write_status_debug(t_philo_status status, t_philo *philo, \
long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		ft_printf(W"%d"RST" %d has taken the 1st fork "
			"\t\t\tn"B"[	%d	]\n"RST, elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		ft_printf(W"%d"RST" %d has taken the 2nd fork "
			"\t\t\tn"B"[	%d	]\n"RST, elapsed, philo->id,
			philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		ft_printf(W"%d"C" %d is eating"
			"\t\t\tn"Y"[	%d	]\n"RST, elapsed, philo->id,
			philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		ft_printf(W"%d"RST" %d is sleeping \n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		ft_printf(W"%d"RST" %d is thinking \n", elapsed, philo->id);
	else if (DIED == status)
		ft_printf(RED"\t\t %d %d died\n"RST, elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((status == TAKE_FIRST_FORK || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->table))
			ft_printf(W"%d"RST" %d has taken a fork \n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			ft_printf(W"%d"C" %d is eating \n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			ft_printf(W"%d"RST" %d is sleeping \n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			ft_printf(W"%d"RST" %d is thinking \n", elapsed, philo->id);
		else if (DIED == status)
			ft_printf(RED"%d"RST" %d died\n"RST, elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
