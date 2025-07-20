/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:00:08 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 01:55:41 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	debug_print_struct(t_data *data)
{
	printf("nb_philo = %d \n", data->nb_philo);
	printf("time_die %ld\n", data->time_die);
	printf("time_slp %ld\n", data->time_slp);
	printf("time_eat %ld\n", data->time_eat);
	printf("goal = %d\n", data->eat_goal);
	return (0);
}

void	clear_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(data->fork[i]);
		free(data->fork[i]);
		i++;
	}
	free(data->philos);
	free(data->fork);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 1));
	if (arg_check(argc, argv) || init_simulation(argc, argv, data))
		return (free(data), 1);
	monitoring(data);
	printf("%s[%ld] sim is over !\n%s", \
		CLR_RED, get_sim_time(data->philos[0].start), CLR_CLOSE);
	clear_data(data);
	return (0);
}
