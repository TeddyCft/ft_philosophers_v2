/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:29:43 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 18:32:24 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_sim_time(size_t start)
{
	struct timeval	time;
	size_t			sim_time;

	gettimeofday(&time, NULL);
	sim_time = ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
	return (sim_time);
}
