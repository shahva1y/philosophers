#include "philo_bonus.h"

void	ft_destroy_t_sem(t_sem *sem)
{
	if (sem)
	{
		sem_close(sem->finish);
		sem_close(sem->print);
		sem_close(sem->take);
		sem_close(sem->forks);
		if (sem->full)
		{
			sem_post(sem->full);
			sem_close(sem->full);
		}
		free(sem);
	}
}

void	ft_unlink_t_sem(void)
{
	sem_unlink("/fork");
	sem_unlink("/take");
	sem_unlink("/print");
	sem_unlink("/full");
	sem_unlink("/finish");
}

t_sem	*ft_open_t_sem(t_sem *sem, t_args *args)
{
	if (sem && args)
	{
		sem->forks = sem_open("/fork", O_CREAT, 0666,
				args->number_of_philosophers);
		sem->take = sem_open("/take", O_CREAT, 0666, 1);
		sem->print = sem_open("/print", O_CREAT, 0666, 1);
		sem->full = NULL;
		if (args->must_eat_count != -1)
		{
			sem->full = sem_open("/full", O_CREAT | O_EXCL, S_IRWXU,
					args->number_of_philosophers);
			ft_lock_sem_t(sem->full, args->number_of_philosophers);
		}
		sem->finish = sem_open("/finish", O_CREAT, 0666, 1);
	}
	return (sem);
}

t_sem	*ft_init_t_sem(t_args *args)
{
	t_sem	*sem;

	sem = NULL;
	if (args)
	{
		sem = malloc(sizeof(t_sem));
		if (sem)
		{
			ft_unlink_t_sem();
			ft_open_t_sem(sem, args);
		}
	}
	return (sem);
}

void	ft_lock_sem_t(sem_t *sem, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		sem_wait(sem);
		i++;
	}
}
