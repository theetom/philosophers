/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:18 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:28 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_dinner(void *data)
{
	t_table	*table;

	table = (t_table *)data;

	// make sure all philos running

	while (!all_threads_running())
	{
		
	}
	return (NULL);
}