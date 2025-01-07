/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:04:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/01/06 13:46:28 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_status(t_philo_status status, t_philo *philo, long death)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
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
		ft_printf(RED"%d"RST" %d died\n"RST, death, philo->id);
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
