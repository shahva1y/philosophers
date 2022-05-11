#include "philo.h"

void	*ft_philosopher(void *param)
{
	t_philo				*philo;

	philo = (t_philo *) param;
	if (philo)
	{
		if (philo->index % 2 == 0)
			ft_timer(((philo->global)->args)->time_to_eat / 2);
		while ((philo->global)->status != END)
		{
			ft_take_forks(philo, philo->next, philo);
			ft_eat(philo);
			ft_put_forks(philo, philo->next, philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (NULL);
}
