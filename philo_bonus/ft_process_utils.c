#include "philo_bonus.h"

static int	ft_child_process(t_philo *philo)
{
	pthread_t	check_thread;

	if (pthread_create(&check_thread, NULL, ft_check_time_limits, philo))
	{
		write(2, "pthread_create error\n", 21);
		sem_post((philo->sem)->finish);
		exit(-1);
	}
	pthread_detach(check_thread);
	ft_philosopher(philo);
	return (0);
}

void	ft_kill_child_processes(pid_t *pid_philo)
{
	int	i;

	if (pid_philo)
	{
		i = 0;
		while (pid_philo[i] != -1 && pid_philo[i] != 0)
		{
			kill(pid_philo[i], SIGKILL);
			i++;
		}
		memset(pid_philo, 0, sizeof(pid_t) * (i + 1));
	}
}

int	ft_init_philo_processes(t_philo *table, pid_t **pid_philo)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = table;
	while (i < (table->args)->number_of_philosophers)
	{
		(*pid_philo)[i] = fork();
		if (!(*pid_philo)[i])
			ft_child_process(philo);
		if ((*pid_philo)[i] == -1)
		{
			sem_post((table->sem)->finish);
			return (-1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}
