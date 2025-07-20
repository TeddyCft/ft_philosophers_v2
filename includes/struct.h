/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:58:36 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 20:17:20 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_status
{
	S_START,
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
}		t_status;

typedef struct s_rules
{

}		t_rules;

typedef struct s_philo
{
	pthread_mutex_t	fork_mtx;
	struct s_data	*data;
	enum e_status	status;
	pthread_t		thread;
	t_rules			rules;
	size_t			start;
	size_t			last_meal;
	int				id;
	int				meal_count;
}		t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				time_slp;
	int				time_eat;
	int				time_die;
	int				nb_philo;
	int				eat_goal;
	size_t			start;
	char			sim;
}		t_data;

#endif