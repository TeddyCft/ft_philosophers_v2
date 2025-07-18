/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:00:08 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 19:26:25 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	debug_print_struct(t_data *data)
{
	printf("nb_philo = %d \n", data->nb_philo);
	printf("time_die %d\n", data->time_die);
	printf("time_slp %d\n", data->time_slp);
	printf("time_eat %d\n", data->time_eat);
	printf("goal = %d\n", data->eat_goal);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 1));
	if (arg_check(argc, argv) || init_simulation(argc, argv, data))
		return (free(data), 1);
	debug_print_struct(data);
	while (data->sim)
		;
	printf("%s[%ld] sim is over !\n%s", \
		CLR_RED, get_sim_time(data->start), CLR_CLOSE);
	free(data);
	return (0);
}
