/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:33:15 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 13:34:36 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	everyone_is_fed(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (!data->philos[i].is_fed)
			return (0);
		i++;
	}
	data->sim = 0;
	printf("%s[%ld] Everyone is fed !%s\n", \
		CLR_GREEN, get_sim_time(data->start), CLR_CLOSE);
	return (1);
}

int	should_die(t_philo *philo)
{
	size_t	time;

	time = get_sim_time(philo->data->start);
	if (philo->data->time_die < time - philo->last_meal)
	{
		printf("%s%ld %d died %s\n", CLR_RED, time, philo->id, CLR_CLOSE);
		return (1);
	}
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
				data->sim = 0;
				return ;
			}
			if (everyone_is_fed(data))
				return ;
			i++;
		}
	}
}
