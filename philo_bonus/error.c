/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:43 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:14:54 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(t_sem *sem, char *error_message)
{
	sem_wait(sem->print);
	printf("%s", error_message);
	sem_post(sem->finish);
	exit(1);
}
