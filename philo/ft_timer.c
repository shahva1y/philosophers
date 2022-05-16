/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:11:27 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:11:31 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_timer(unsigned long long ms)
{
	t_time	init_time;

	init_time = ft_get_time(0);
	while (ft_get_time(init_time) < ms)
		usleep(10);
	return (0);
}

unsigned long long	ft_get_time(unsigned long long init_time)
{
	unsigned long long	time;
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	time = 1000 * (unsigned long long)tv.tv_sec
		+ (unsigned long long)(tv.tv_usec / 1000);
	return (time - init_time);
}

int	ft_synchronize_time(t_philo *table)
{
	t_philo		*tmp;
	t_time		init_time;

	if (!table)
		return (-1);
	init_time = ft_get_time(0);
	if (init_time < 0)
		return (-1);
	tmp = table;
	while (tmp->next != table)
	{
		tmp->init_time = init_time;
		tmp->time = init_time;
		tmp = tmp->next;
	}
	tmp->init_time = init_time;
	tmp->time = init_time;
	return (0);
}
