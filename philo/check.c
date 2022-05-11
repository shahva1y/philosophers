#include "philo.h"

void	*ft_check_eat_limits(void *param)
{
	t_philo		*table;
	int			count;

	table = (t_philo *)param;
	if (table)
	{
		count = 0;
		while (count < ((table->global)->args)->number_of_philosophers
			&& (table->global)->status != END)
		{
			if (table->eating_count < ((table->global)->args)->must_eat_count)
				count = 0;
			else
				count += 1;
			table = table->next;
		}
		if ((table->global)->status == END)
			return (NULL);
		pthread_mutex_lock(&((table->global)->mut_print));
		(table->global)->status = END;
		ft_unlock_t_philo_list(table);
		pthread_mutex_unlock(&((table->global)->mut_print));
	}
	return (NULL);
}

void	*ft_check_time_limits(void *param)
{
	t_philo				*table;
	unsigned long long	time_to_die;

	table = (t_philo *)param;
	if (table)
	{
		time_to_die = ((table->global)->args)->time_to_die;
		while (ft_get_time(0) - table->time <= time_to_die
			&& (table->global)->status != END)
			table = table->next;
		if ((table->global)->status == END)
			return (NULL);
		pthread_mutex_lock(&((table->global)->mut_print));
		(table->global)->status = END;
		printf("%llu %d died\n", ft_get_time(table->init_time), table->index);
		ft_unlock_t_philo_list(table);
		pthread_mutex_unlock(&((table->global)->mut_print));
	}
	return (NULL);
}
