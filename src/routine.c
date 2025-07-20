/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 01:26:47 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, t_data *data)
{
	int	is_last;

	is_last = (philo->id == data->nb_philo);
	if (is_last)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	philo->status = S_FORK;
	if (is_last)
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
	philo->start = get_sim_time(0);
	while (philo->data->sim)
	{
		philo->status = S_THINK;
		take_forks(philo, philo->data);
		philo->status = S_EAT;
		philo->last_meal = get_sim_time(philo->start);
		get_usleep(philo, S_EAT);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		philo->status = S_SLEEP;
		get_usleep(philo, S_SLEEP);
	}
	return (NULL);
}
