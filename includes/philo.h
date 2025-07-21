/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:57:20 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/07/21 13:46:57 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "proto.h"
# include <stdint.h>

/////// COLORS //////

# ifndef CLR_RED
#  define CLR_RED "\033[0;31m"
# endif

# ifndef CLR_GREEN
#  define CLR_GREEN "\033[0;32m"
# endif

# ifndef CLR_YELLOW
#  define CLR_YELLOW "\033[0;33m"
# endif

# ifndef CLR_BLUE
#  define CLR_BLUE "\033[0;34m"
# endif

# ifndef CLR_PURPLE
#  define CLR_PURPLE "\033[0;35m"
# endif

# ifndef CLR_CYAN
#  define CLR_CYAN "\033[0;36m"
# endif

# ifndef CLR_WHITE
#  define CLR_WHITE "\033[0;37m"
# endif

# ifndef CLR_CLOSE
#  define CLR_CLOSE "\033[0m"
# endif

///////////////////

#endif