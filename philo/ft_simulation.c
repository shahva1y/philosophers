/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:10:50 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:10:53 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation(t_philo *table)
{
	pthread_t		*philo_thread;
	pthread_t		check_thread[2];
	int				result[2];
	int				number_of_philos;

	if (table)
	{
		number_of_philos = ((table->global)->args)->number_of_philosophers;
		philo_thread = malloc(sizeof(pthread_t) * number_of_philos);
		if (!philo_thread)
			return (-1);
		result[0] = ft_init_check_pthread_t(check_thread, table);
		result[1] = ft_init_philo_pthread_t(philo_thread, table);
		if (result[0] || result[1])
		{
			ft_free(philo_thread);
			return (-1);
		}
		ft_join_check_pthread_t(check_thread, table);
		ft_join_philo_pthread_t(philo_thread, number_of_philos);
		ft_free(philo_thread);
		return (0);
	}
	return (-1);
}
