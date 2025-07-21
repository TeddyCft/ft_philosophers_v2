/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:58:36 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 11:12:45 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_fork_dir
{
	F_LEFT,
	F_RIGHT
}		t_fork_dir;

typedef enum e_status
{
	S_START,
	S_FORK,
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
}		t_status;

typedef struct s_philo
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data;
	enum e_status	status;
	pthread_t		thread;
	size_t			last_meal;
	size_t			start;
	int				id;
	int				meal_count;
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t	**fork;
	t_status		*status;
	t_philo			*philos;
	size_t			start;
	size_t			time_slp;
	size_t			time_eat;
	size_t			time_die;
	int				nb_philo;
	int				eat_goal;
	char			sim;
}		t_data;

#endif