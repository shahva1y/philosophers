/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_t_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:10:39 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:10:43 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo_pthread_t(pthread_t *philo_thread, t_philo *table)
{
	t_philo	*philo;
	int		result;
	int		i;

	i = 0;
	philo = table;
	while (i < ((table->global)->args)->number_of_philosophers)
	{
		result = pthread_create(philo_thread + i, NULL, ft_philosopher, philo);
		if (result)
		{
			(table->global)->status = END;
			ft_join_philo_pthread_t(philo_thread, i);
			printf("pthread_create error\n");
			return (-1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}

int	ft_init_check_pthread_t(pthread_t *check_thread, t_philo *table)
{
	int	result[2];

	result[1] = 0;
	result[0] = pthread_create(&check_thread[0], NULL,
			ft_check_time_limits, table);
	if (result[0])
	{
		(table->global)->status = END;
		return (-1);
	}
	if (((table->global)->args)->must_eat_count != -1)
		result[1] = pthread_create(&check_thread[1], NULL,
				ft_check_eat_limits, table);
	if (result[1])
	{
		(table->global)->status = END;
		return (-1);
	}
	return (0);
}

void	ft_join_philo_pthread_t(pthread_t *philo_thread, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
}

void	ft_join_check_pthread_t(pthread_t *check_thread, t_philo *table)
{
	pthread_join(check_thread[0], NULL);
	if (((table->global)->args)->must_eat_count != -1)
		pthread_join(check_thread[1], NULL);
}
