#include "philo.h"

t_global	*ft_init_t_global(t_args *args)
{
	t_global	*global;

	global = NULL;
	if (args)
	{
		global = malloc(sizeof(t_global));
		if (global)
		{
			global->status = PLAY;
			if (pthread_mutex_init(&(global->mut_print), NULL))
			{
				free(global);
				return (NULL);
			}
			global->args = args;
		}
	}
	return (global);
}

void	ft_destroy_t_global(t_global *global)
{
	if (global)
	{
		pthread_mutex_destroy(&(global->mut_print));
		free(global);
	}
}
