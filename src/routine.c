/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 13:40:18 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_offset(t_philo *philo)
{
	if (philo->id % 2)
		usleep(1000);
}

void	take_forks(t_philo *philo)
{
	int			is_even;

	is_even = philo->id % 2;
	if (is_even)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	philo->status = S_FORK;
	print_status(philo);
	if (is_even)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->data->sim)
		;
	phi_offset(philo);
	while (philo->data->sim)
	{
		philo->status = S_THINK;
		print_status(philo);
		take_forks(philo);
		philo->status = S_EAT;
		print_status(philo);
		philo->last_meal = get_sim_time(philo->data->start);
		philo->meal_count++;
		if (philo->meal_count == philo->data->eat_goal)
			philo->is_fed = 1;
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		philo->status = S_SLEEP;
		print_status(philo);
		usleep(philo->data->time_slp * 1000);
	}
	return (NULL);
}
