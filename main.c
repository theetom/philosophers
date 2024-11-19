/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:59:10 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/19 15:53:31 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// https://medium.com/@jalal92/the-dining-philosophers-7157cc05315

// 1.14.24

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 | argc == 6)
	{
		/* 		correct input
		1) errors checking, filling table table */
		parse_input(&table, argv); /* //TO DO */

		// 2) creating the actual thing
		data_init(&table);

		// 3)
		dinner_start(&table);

		// 4) no leaks ->philos full |1 philo died
		clean(&table);
	}
	else
	{
		// 
		error_exit("Wrong input:\n"
				G"Correct is ./philosophers 5 800 200 200 [5]"RST);
	}
}
