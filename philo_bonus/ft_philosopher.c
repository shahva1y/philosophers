/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:15:34 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:15:38 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philosopher(t_philo *philo)
{
	if (philo)
	{
		while (1)
		{
			ft_take_forks(philo);
			ft_eat(philo);
			ft_put_forks(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	exit(0);
}
