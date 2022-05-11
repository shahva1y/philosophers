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
