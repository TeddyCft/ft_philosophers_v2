/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:33:15 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 01:57:24 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	should_die(t_philo *philo)
{
	size_t	time;

	time = get_sim_time(philo->start);
	if (philo->data->time_die < time - philo->last_meal)
		return (1);
	return (0);
}

void	monitoring(t_data *data)
{
	int	i;

	usleep(500);
	while (data->sim)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (should_die(&data->philos[i]))
			{
				data->philos[i].status = S_DEAD;
				print_status(&data->philos[i]);
				data->sim = 0;
				return ;
			}
			if (data->philos[i].status != data->status[i])
			{
				print_status(&data->philos[i]);
				data->status[i] = data->philos[i].status;
			}
			i++;
		}
	}
}
