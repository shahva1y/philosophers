/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_global_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:11:04 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:11:07 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_global	*ft_init_t_global(t_args *args)
{
	t_global	*global;

	global = NULL;
	if (args)
	{
		global = malloc(sizeof(t_global));
		if (global)
		{
			global->status = PLAY;
			if (pthread_mutex_init(&(global->mut_print), NULL))
			{
				free(global);
				return (NULL);
			}
			if (pthread_mutex_init(&(global->mut_check), NULL))
			{
				pthread_mutex_destroy(&(global->mut_print));
				free(global);
				return (NULL);
			}
			global->args = args;
		}
	}
	return (global);
}

void	ft_destroy_t_global(t_global *global)
{
	if (global)
	{
		pthread_mutex_destroy(&(global->mut_print));
		pthread_mutex_destroy(&(global->mut_check));
		free(global);
	}
}
