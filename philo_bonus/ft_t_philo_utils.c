/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:16:44 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:16:47 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_init_t_philo(t_args *args, t_sem *sem, int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->next = philo;
	philo->index = index;
	philo->args = args;
	philo->sem = sem;
	philo->eating_count = 0;
	philo->init_time = ft_get_time(0);
	philo->time = philo->init_time;
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
		while (tmp->next != (*table))
			tmp = tmp->next;
		tmp->next = philo;
		philo->next = (*table);
	}
}

t_philo	*ft_init_t_philo_list(t_args *args, t_sem *sem)
{
	t_philo		*list;
	t_philo		*philo;
	int			i;

	list = NULL;
	if (args && sem)
	{
		i = 0;
		while (i < args->number_of_philosophers)
		{
			philo = ft_init_t_philo(args, sem, i + 1);
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

void	ft_free_t_philo_list(t_philo *list)
{
	t_philo	*philo;
	t_philo	*current;

	if (list)
	{
		ft_destroy_t_sem(list->sem);
		philo = list;
		while (philo->next != list)
		{
			current = philo;
			philo = philo->next;
			free(current);
		}
		free(philo);
	}
}
