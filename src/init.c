/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:24:06 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/20 23:52:21 by tcoeffet         ###   ########.fr       */
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
	int		i;

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
		if (i == 0)
			data->philos->left = data->fork[data->nb_philo];
		else
			data->philos->left = data->fork[i - 1];
		if (i == data->nb_philo)
			data->philos->right = data->fork[0];
		else
			data->philos->right = data->fork[i + 1];
		i++;
	}
	return (0);
}

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 23), 1);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
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
	if (!data->nb_philo || !data->time_die || !data->time_eat || \
		!data->time_slp || (ac == 6 && !data->eat_goal))
		return (write(STDERR_FILENO, "philo : argument 0 is invalid\n", 31), 1);
	if (create_forks(data))
		return (1);
	if (create_philos(data))
		return (free(data->fork), 1);
	launch_routines(data);
	data->start = get_sim_time(0);
	data->sim = 1;
	usleep(15000);
	data->sim = 0;
	return (0);
}
