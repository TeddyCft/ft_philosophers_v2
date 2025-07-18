/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:10:58 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 19:28:12 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!philo->data->sim)
		;
	printf("%s[%ld] philo n[%d] started%s\n", \
		CLR_BLUE, get_sim_time(philo->data->start), philo->id, CLR_CLOSE);
	return (NULL);
}
