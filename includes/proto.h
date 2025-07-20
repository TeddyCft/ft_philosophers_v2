/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:58:14 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/18 20:40:48 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "struct.h"

size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

int		init_simulation(int ac, char **av, t_data *data);
int		arg_check(int ac, char **av);

void	*routine(void *arg);

size_t	get_sim_time(size_t start);
void	print_status(t_philo *philo);
void	get_usleep(t_philo *philo, t_status stat);

#endif