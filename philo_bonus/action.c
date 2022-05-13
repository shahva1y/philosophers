/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:17 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:14:21 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_take_forks(t_philo *philo)
{
	sem_wait((philo->sem)->take);
	sem_wait((philo->sem)->forks);
	sem_wait((philo->sem)->print);
	printf("%llu %d has taken a fork\n",
		ft_get_time(philo->init_time), philo->index);
	sem_post((philo->sem)->print);
	sem_wait((philo->sem)->forks);
	sem_wait((philo->sem)->print);
	printf("%llu %d has taken a fork\n",
		ft_get_time(philo->init_time), philo->index);
	sem_post((philo->sem)->print);
	sem_post((philo->sem)->take);
}

void	ft_put_forks(t_philo *philo)
{
	sem_post((philo->sem)->forks);
	sem_post((philo->sem)->forks);
}

void	ft_sleep(t_philo *philo)
{
	sem_wait((philo->sem)->print);
	printf("%llu %d is sleeping\n", ft_get_time(philo->init_time), philo->index);
	sem_post((philo->sem)->print);
	ft_timer((philo->args)->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	sem_wait((philo->sem)->print);
	printf("%llu %d is thinking\n", ft_get_time(philo->init_time), philo->index);
	sem_post((philo->sem)->print);
}

void	ft_eat(t_philo	*philo)
{
	sem_wait((philo->sem)->check);
	philo->time = ft_get_time(0);
	sem_post((philo->sem)->check);
	sem_wait((philo->sem)->print);
	printf("%llu %d is eating\n", ft_get_time(philo->init_time), philo->index);
	sem_post((philo->sem)->print);
	ft_timer((philo->args)->time_to_eat);
	philo->eating_count += 1;
	if (philo->eating_count == (philo->args)->must_eat_count)
		sem_post((philo->sem)->full);
}
