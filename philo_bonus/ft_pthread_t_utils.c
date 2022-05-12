/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_t_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:16:20 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:16:25 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_destroy_philo_pthread_t(pthread_t *philo_thread, int number)
{
	int		i;

	i = 0;
	while (i < number)
	{
		pthread_join(philo_thread[i], NULL);
		pthread_detach(philo_thread[i]);
		i++;
	}
}

void	ft_destroy_check_pthread_t(pthread_t *check_thread, t_philo *table)
{
	pthread_join(check_thread[0], NULL);
	pthread_detach(check_thread[0]);
	if ((table->args)->must_eat_count != -1)
	{
		pthread_join(check_thread[1], NULL);
		pthread_detach(check_thread[1]);
	}
}
