/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:24:06 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 19:26:38 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch_routines(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philo)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
}

int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 23), 1);
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].meal_count = 0;
		data->philos[i].status = S_START;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	init_simulation(int ac, char **av, t_data *data)
{
	if (ac == 6)
		data->eat_goal = ft_atoi(av[5]);
	else
		data->eat_goal = -1;
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_slp = ft_atoi(av[4]);
	if (create_philos(data))
		return (1);
	launch_routines(data);
	data->start = get_sim_time(0);
	data->sim = 1;
	usleep(15000);
	data->sim = 0;
	return (0);
}
