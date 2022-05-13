/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:29 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:14:35 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_eat_limits(void *param)
{
	t_philo	*table;

	table = (t_philo *)param;
	if (table)
	{
		ft_lock_sem_t((table->sem)->full,
			(table->args)->number_of_philosophers);
		sem_wait((table->sem)->print);
		sem_post((table->sem)->finish);
	}
	return (NULL);
}

void	*ft_check_time_limits(void *param)
{
	t_philo				*philo;
	unsigned long long	delta;

	delta = 0;
	philo = (t_philo *)param;
	if (philo)
	{
		//unsigned long long time = 0;
		//unsigned long long philo_time = 0;
		sem_wait((philo->sem)->check);
		while (delta <= (philo->args)->time_to_die)
		{
			delta = ft_get_time(0) - philo->time;
			sem_post((philo->sem)->check);
			usleep(1000);
			sem_wait((philo->sem)->check);
		}
		printf("%llu\n", delta);
		//printf("%llu\n", time);
		//printf("%llu\n", philo_time);
		sem_wait((philo->sem)->print);
		printf("%llu %d died\n", ft_get_time(philo->init_time), philo->index);
		sem_post((philo->sem)->finish);
	}
	return (NULL);
}
