/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:12:26 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:12:29 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_args
{
	int					number_of_philosophers;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					must_eat_count;
}		t_args;

typedef enum s_status
{
	PLAY,
	END,
}	t_status;

typedef struct s_global
{
	t_status		status;
	t_args			*args;
	pthread_mutex_t	mut_print;
}		t_global;

typedef struct s_philo
{
	struct s_philo		*next;
	int					index;
	pthread_mutex_t		fork;
	unsigned long long	time;
	unsigned long long	init_time;
	int					eating_count;
	t_global			*global;
}		t_philo;

typedef unsigned long long	t_time;
typedef char				t_complete;

int					ft_atoi(char *str);
int					ft_unsigned_representable(char *str);
void				ft_free(void *ptr);

int					ft_simulation(t_philo *table);
void				*ft_philosopher(void *param);
void				*ft_check_time_limits(void *param);
void				*ft_check_eat_limits(void *param);

t_philo				*ft_init_table(t_args *args);
void				ft_destroy_table(t_philo *table);

t_philo				*ft_init_t_philo(t_global *global);
t_philo				*ft_init_t_philo_list(t_global *global);
void				ft_add_t_philo_list(t_philo **table, t_philo *philo);
void				ft_free_t_philo_list(t_philo *table);
void				ft_unlock_t_philo_list(t_philo *table);

t_global			*ft_init_t_global(t_args *args);
void				ft_destroy_t_global(t_global *global);

void				ft_take_forks(t_philo *philo, t_philo *min, t_philo *max);
void				ft_put_forks(t_philo *philo, t_philo *min, t_philo *max);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
void				ft_eat(t_philo	*philo);

int					ft_timer(unsigned long long ms);
unsigned long long	ft_get_time(unsigned long long init_time);
int					ft_synchronize_time(t_philo *table);

int					ft_init_philo_pthread_t(pthread_t *philo_thread,
						t_philo *table);
void				ft_join_philo_pthread_t(pthread_t *philo_thread,
						int number);
int					ft_init_check_pthread_t(pthread_t *check_thread,
						t_philo *table);
void				ft_join_check_pthread_t(pthread_t *check_thread,
						t_philo *table);
#endif
