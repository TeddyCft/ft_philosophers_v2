/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 11:57:16 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, t_data *data)
{
	int			is_even;

	(void) data;
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
	usleep(200);
	while (philo->data->sim)
	{
		philo->status = S_THINK;
		print_status(philo);
		take_forks(philo, philo->data);
		philo->status = S_EAT;
		print_status(philo);
		philo->meal_count++;
		if (philo->meal_count == philo->data->eat_goal)
			philo->is_fed = 1;
		philo->last_meal = get_sim_time(philo->data->start);
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		philo->status = S_SLEEP;
		print_status(philo);
		usleep(philo->data->time_slp * 1000);
	}
	return (NULL);
}
