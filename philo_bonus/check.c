#include "philo_bonus.h"

void	*ft_check_eat_limits(void *param)
{
	t_philo	*table;

	table = (t_philo *)param;
	if (table)
	{
		ft_lock_sem_t((table->sem)->full,
			(table->args)->number_of_philosophers);
		sem_wait((table->sem)->print);
		sem_post((table->sem)->finish);
	}
	return (NULL);
}

void	*ft_check_time_limits(void *param)
{
	t_philo		*philo;

	philo = (t_philo *)param;
	if (philo)
	{
		while (ft_get_time(0) - philo->time <= (philo->args)->time_to_die)
			;
		sem_wait((philo->sem)->print);
		sem_post((philo->sem)->finish);
		printf("%llu %d died\n", ft_get_time(philo->init_time), philo->index);
	}
	return (NULL);
}
