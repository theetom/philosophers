/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:13:10 by toferrei          #+#    #+#             */
/*   Updated: 2025/01/08 12:55:23 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_there_comma(char **argv, t_table *table)
{
	int	n;
	int	m;

	m = 0;
	n = 1;
	while (argv[n])
	{
		while (argv[n][m])
		{
			if ((argv[n][m] < '0' || argv[n][m] > '9') && argv[n][m] != '+')
			{
				table->error = true;
				error_exit("Only Positive Integers");
				return (1);
			}
			m++;
		}
		m = 0;
		n++;
	}
	return (0);
}
