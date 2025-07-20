/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 20:18:37 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	die(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->time_die < get_sim_time(philo->start) - philo->last_meal)
		return (0);
	philo->status = S_DEAD;
	print_status(philo);
	data->sim = 0;
	return (1);
}

void	sleep(t_philo *philo)
{
	philo->status = S_SLEEP;
	print_status(philo);
	get_usleep(philo, S_SLEEP);
	if (die(philo))
		return ;
}

void	eat(t_philo *philo)
{
	philo->status = S_EAT;
	print_status(philo);
	philo->last_meal = get_sim_time(philo->start);
	get_usleep(philo, S_EAT);
	if (die(philo))
		return ;
	sleep(philo);
	return ;
}

int	can_eat(t_philo *philo)
{
	if (fourchettes_dispo())
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->data->sim)
		;
	philo->start = get_sim_time(0);
	while (philo->data->sim)
	{
		if (die)
			return (NULL);
		else if (can_eat(philo))
			eat(philo);
		else if (philo->status != S_THINK)
		{
			philo->status = S_THINK;
			print_status(philo);
		}
	}
	return (NULL);
}
