/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:17:23 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:17:29 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isvalid_arguments(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_unsigned_representable(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static t_args	*ft_parse_arguments(int count, char **argv)
{
	t_args	*args;

	if (count > 5 || count < 4 || !ft_isvalid_arguments(argv))
	{
		printf("Incorrect arguments format! Only 4 or 5 positive int values\n");
		return (NULL);
	}
	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->number_of_philosophers = ft_atoi(argv[0]);
	args->time_to_die = (unsigned long long) ft_atoi(argv[1]);
	args->time_to_eat = (unsigned long long) ft_atoi(argv[2]);
	args->time_to_sleep = (unsigned long long) ft_atoi(argv[3]);
	if (count == 5)
		args->must_eat_count = ft_atoi(argv[4]);
	else
		args->must_eat_count = -1;
	if (args->number_of_philosophers == 0)
	{
		printf("Incorrect arguments format! Number of philo is 0\n");
		ft_free(args);
		return (NULL);
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_args		*args;
	t_philo		*table;

	args = ft_parse_arguments((argc - 1), (argv + 1));
	table = ft_init_table(args);
	ft_simulation(table);
	ft_free_t_args(args);
	ft_free_t_philo_list(table);
	return (0);
}
