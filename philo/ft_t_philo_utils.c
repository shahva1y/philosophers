/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:11:16 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:11:21 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_t_philo_list(t_philo *list)
{
	t_philo	*philo;
	t_philo	*current;

	if (list)
	{
		philo = list;
		while (philo->next != list)
		{
			current = philo;
			pthread_mutex_destroy(&(philo->fork));
			philo = philo->next;
			free(current);
		}
		free(philo);
	}
}

t_philo	*ft_init_t_philo(t_global *global)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = philo;
	philo->index = 1;
	if (pthread_mutex_init(&(philo->fork), NULL))
	{
		free(philo);
		return (NULL);
	}
	philo->global = global;
	philo->eating_count = 0;
	return (philo);
}

void	ft_add_t_philo_list(t_philo **table, t_philo *philo)
{
	t_philo	*tmp;

	if (!(*table))
		(*table) = philo;
	else
	{
		tmp = (*table);
		philo->index = 2;
		while (tmp->next != (*table))
		{
			tmp = tmp->next;
			philo->index += 1;
		}
		tmp->next = philo;
		philo->next = (*table);
	}
}

t_philo	*ft_init_t_philo_list(t_global *global)
{
	t_philo		*list;
	t_philo		*philo;
	int			i;

	list = NULL;
	if (global)
	{
		i = 0;
		while (i < (global->args)->number_of_philosophers)
		{
			philo = ft_init_t_philo(global);
			if (!philo)
			{
				ft_free_t_philo_list(list);
				return (NULL);
			}
			ft_add_t_philo_list(&list, philo);
			i++;
		}
	}
	return (list);
}

void	ft_unlock_t_philo_list(t_philo *table)
{
	t_philo	*philo;

	philo = table;
	while (philo->next != table)
	{
		pthread_mutex_unlock(&(philo->fork));
		philo = philo->next;
	}
	pthread_mutex_unlock(&(philo->fork));
}
