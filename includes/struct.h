/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:58:36 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 15:37:32 by tcoeffet         ###   ########.fr       */
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

typedef struct s_data
{
	int	time_slp;
	int	time_eat;
	int	time_die;
	int	nb_philo;
	int	eat_goal;

}	t_data;

#endif