#include "philo_bonus.h"

t_philo	*ft_init_table(t_args *args)
{
	t_philo		*table;
	t_sem		*sem;
	int			result;

	table = NULL;
	if (args)
	{
		sem = ft_init_t_sem(args);
		table = ft_init_t_philo_list(args, sem);
		result = ft_synchronize_time(table);
		if (!sem || !table || result < 0)
		{
			ft_destroy_t_sem(sem);
			ft_free_t_philo_list(table);
			return (NULL);
		}
	}
	return (table);
}
