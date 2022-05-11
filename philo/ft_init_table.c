#include "philo.h"

t_philo	*ft_init_table(t_args *args)
{
	t_philo		*table;
	t_global	*global;
	int			result;

	table = NULL;
	if (args)
	{
		global = ft_init_t_global(args);
		table = ft_init_t_philo_list(global);
		result = ft_synchronize_time(table);
		if (!global || !table || result < 0)
		{
			ft_destroy_t_global(global);
			ft_free_t_philo_list(table);
			return (NULL);
		}
	}
	return (table);
}

void	ft_destroy_table(t_philo *table)
{
	if (table)
	{
		ft_destroy_t_global(table->global);
		ft_free_t_philo_list(table);
	}
}
