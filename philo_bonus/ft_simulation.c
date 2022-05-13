/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:16:32 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:16:35 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static pid_t	*ft_init_philos_pid(int count)
{
	pid_t		*pid_philo;

	pid_philo = malloc(sizeof(pid_t) * (count + 1));
	if (!pid_philo)
		return (NULL);
	memset(pid_philo, 0, sizeof(pid_t) * (count + 1));
	return (pid_philo);
}

int	ft_simulation(t_philo	*table)
{
	pid_t		*pid_philo;
	pthread_t	check_thread;

	if (table)
	{
		pid_philo = ft_init_philos_pid((table->args)->number_of_philosophers);
		if (!pid_philo)
			return (-1);
		sem_wait((table->sem)->finish);
		if ((table->args)->must_eat_count != -1)
		{
			if (pthread_create(&check_thread, NULL, ft_check_eat_limits, table))
			{
				ft_free(pid_philo);
				return (-1);
			}
			pthread_detach(check_thread);
		}
		ft_init_philo_processes(table, &pid_philo);
		sem_wait((table->sem)->finish);
		write(1, "Whats happen! This message i dont see!\n", 39);
		ft_kill_child_processes(pid_philo);
		ft_free(pid_philo);
	}
	return (0);
}
