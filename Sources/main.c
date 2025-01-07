/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:10 by toferrei          #+#    #+#             */
/*   Updated: 2025/01/07 16:16:07 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	table.error = false;
	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
		if (table.error == true)
			return (1);
		data_init(&table);
		if (table.error == false)
			dinner_start(&table);
		clean(&table);
	}
	else
		error_exit("Wrong input:\n"
			"Correct is ./philosophers 5 800 200 200 [5]"RST);
	return (0);
}
