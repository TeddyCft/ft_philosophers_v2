/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:36:06 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/20 23:38:44 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(char *str, int i)
{
	int	p;
	int	m;

	p = 0;
	m = 0;
	if (str[0] == '-')
		m = 1;
	if (str[0] == '+')
		p = 1;
	if (i > 11 || ((i == 11) && (p != 1 && m != 1)))
		return (0);
	if (i == 11)
	{
		if (m == 1 && (ft_strncmp(str, "-2147483648", i) > 0))
			return (0);
		if (p == 1 && (ft_strncmp(str, "+2147483647", i) > 0))
			return (0);
	}
	if (i == 10 && m == 0 && str[0] != '-' && \
	ft_strncmp(str, "2147483647", i) > 0)
		return (0);
	return (1);
}

int	is_int(char *str)
{
	int		i;

	i = 0;
	if (str[0] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (i >= 10)
		return (check_int(str, i));
	return (1);
}

int	arg_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 6 || ac == 1)
	{
		write(STDERR_FILENO, "philo : invalid argument count\n", 32);
		return (1);
	}
	while (i < ac)
	{
		if (!is_int(av[i]))
		{
			write(STDERR_FILENO, "philo : [", 10);
			write(STDERR_FILENO, av[i], ft_strlen(av[i]));
			write(STDERR_FILENO, "] : argument invalid\n", 22);
			return (1);
		}
		i++;
	}
	return (0);
}
