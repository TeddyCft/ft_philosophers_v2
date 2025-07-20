/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:24:06 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 01:55:23 by tcoeffet         ###   ########.fr       */
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
		data->philos[i].right = data->fork[i];
		data->philos[i].left = data->fork[i + 1];
		if (i + 1 == data->nb_philo)
			data->philos[i].left = data->fork[0];
		i++;
	}
	return (0);
}

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(pthread_mutex_t *) * data->nb_philo);
	if (!data->fork)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 23), 1);
	while (i < data->nb_philo)
	{
		data->fork[i] = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
		if (!data->fork[i])
		{
			while (i > 0)
			{
				i--;
				free(data->fork[i]);
			}
			free(data->fork);
			return (1);
		}
		pthread_mutex_init(data->fork[i], NULL);
		i++;
	}
	return (0);
}

void	set_data_status(t_data *data, int n)
{
	while (n)
	{
		n--;
		data->status[n] = S_START;
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
	data->status = malloc(sizeof(t_status) * data->nb_philo);
	if (!data->status)
		return (write(STDERR_FILENO, "philo : malloc failed\n", 23), 1);
	set_data_status(data, data->nb_philo);
	if (create_forks(data))
		return (free(data->status), 1);
	if (create_philos(data))
		return (free(data->status), free(data->fork), 1);
	launch_routines(data);
	data->sim = 1;
	return (0);
}
