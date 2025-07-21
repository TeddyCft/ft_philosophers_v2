/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:29:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 13:34:23 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	get_usleep(t_philo *philo, t_status stat)
// {
// 	t_data	*data;

// 	data = philo->data;
// 	if (stat == S_EAT)
// 	{
// 		if (data->time_die > data->time_eat)
// 			usleep(data->time_eat * 1000);
// 		else
// 			usleep(data->time_die * 1000);
// 	}
// 	if (stat == S_SLEEP)
// 	{
// 		if (data->time_die > data->time_eat + data->time_slp)
// 			usleep(data->time_slp * 1000);
// 		else
// 			usleep((data->time_die - data->time_eat) * 1000);
// 	}
// }

void	print_status(t_philo *philo)
{
	size_t		time;
	int			id;

	if (!philo->data->sim)
		return ;
	id = philo->id;
	time = get_sim_time(philo->data->start);
	if (philo->status == S_FORK)
		printf("%ld %d has taken a for\n", time, id);
	if (philo->status == S_EAT)
	{
		printf("%ld %d has taken a for\n", time, id);
		printf("%ld %d is eating\n", time, id);
	}
	if (philo->status == S_SLEEP)
		printf("%ld %d is sleeping\n", time, id);
	if (philo->status == S_THINK)
		printf("%ld %d is thinking\n", time, id);
}
//same with colors
/* void	print_status(t_philo *philo)
{
	size_t		time;
	int			id;

	if (!philo->data->sim)
		return ;
	id = philo->id;
	time = get_sim_time(philo->data->start);
	if (philo->status == S_FORK)
		printf("%s%ld %d has taken a fork%s\n", CLR_WHITE, time, id, CLR_CLOSE);
	if (philo->status == S_EAT)
	{
		printf("%s%ld %d has taken a fork%s\n", CLR_WHITE, time, id, CLR_CLOSE);
		printf("%s%ld %d is eating %s\n", CLR_CYAN, time, id, CLR_CLOSE);
	}
	if (philo->status == S_SLEEP)
		printf("%s%ld %d is sleeping %s\n", CLR_BLUE, time, id, CLR_CLOSE);
	if (philo->status == S_THINK)
		printf("%s%ld %d is thinking %s\n", CLR_YELLOW, time, id, CLR_CLOSE);
} */

size_t	get_sim_time(size_t start)
{
	struct timeval	time;
	size_t			sim_time;

	gettimeofday(&time, NULL);
	sim_time = ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
	return (sim_time);
}
