#include "philo.h"

void	ft_take_forks(t_philo *philo, t_philo *min, t_philo *max)
{
	if ((philo->global)->status != END)
		pthread_mutex_lock(&(min->fork));
	pthread_mutex_lock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		printf("%llu %d has taken a fork\n",
			ft_get_time(philo->init_time), philo->index);
	pthread_mutex_unlock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		pthread_mutex_lock(&(max->fork));
	pthread_mutex_lock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		printf("%llu %d has taken a fork\n",
			ft_get_time(philo->init_time), philo->index);
	pthread_mutex_unlock(&((philo->global)->mut_print));
}

void	ft_put_forks(t_philo *philo, t_philo *min, t_philo *max)
{
	if ((philo->global)->status != END)
	{
		pthread_mutex_unlock(&(max->fork));
		pthread_mutex_unlock(&(min->fork));
	}
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		printf("%llu %d is sleeping\n",
			ft_get_time(philo->init_time), philo->index);
	pthread_mutex_unlock(&((philo->global)->mut_print));
	ft_timer(((philo->global)->args)->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		printf("%llu %d is thinking\n",
			ft_get_time(philo->init_time), philo->index);
	pthread_mutex_unlock(&((philo->global)->mut_print));
}

void	ft_eat(t_philo	*philo)
{
	philo->time = ft_get_time(0);
	pthread_mutex_lock(&((philo->global)->mut_print));
	if ((philo->global)->status != END)
		printf("%llu %d is eating\n",
			ft_get_time(philo->init_time), philo->index);
	pthread_mutex_unlock(&((philo->global)->mut_print));
	ft_timer(((philo->global)->args)->time_to_eat);
	philo->eating_count += 1;
}
