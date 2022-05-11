#include "philo_bonus.h"

void	ft_error(t_sem *sem, char *error_message)
{
	sem_wait(sem->print);
	printf("%s", error_message);
	sem_post(sem->finish);
	exit(1);
}
