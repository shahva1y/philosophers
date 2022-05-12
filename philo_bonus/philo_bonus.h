/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:17:43 by krulindi          #+#    #+#             */
/*   Updated: 2022/05/12 16:17:46 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include <string.h>

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

typedef struct s_sem
{
	sem_t		*finish;
	sem_t		*full;
	sem_t		*forks;
	sem_t		*take;
	sem_t		*print;
}		t_sem;

typedef struct s_philo
{
	struct s_philo		*next;
	int					index;
	t_args				*args;
	t_sem				*sem;
	unsigned long long	time;
	unsigned long long	init_time;
	int					eating_count;
}		t_philo;

typedef unsigned long long	t_time;
typedef char				t_complete;

int					ft_atoi(char *str);
int					ft_unsigned_representable(char *str);
void				ft_free(void *ptr);

int					ft_simulation(t_philo	*table);
void				ft_philosopher(t_philo *philo);
void				*ft_check_time_limits(void *param);
void				*ft_check_eat_limits(void *param);

t_philo				*ft_init_table(t_args *args);
void				ft_destroy_table(t_philo *table);

t_philo				*ft_init_t_philo(t_args *args, t_sem *sem, int index);
t_philo				*ft_init_t_philo_list(t_args *args, t_sem *sem);
void				ft_free_t_philo_list(t_philo *list);
void				ft_unlock_t_philo_list(t_philo *table);

void				ft_take_forks(t_philo *philo);
void				ft_put_forks(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
void				ft_eat(t_philo	*philo);

int					ft_timer(unsigned long long ms);
unsigned long long	ft_get_time(unsigned long long init_time);
int					ft_synchronize_time(t_philo *table);

void				ft_kill_child_processes(pid_t *pid_philo);
int					ft_init_philo_processes(t_philo *table, pid_t **pid_philo);
void				ft_destroy_philo_pthread_t(pthread_t *philo_thread,
						int number);

int					ft_init_check_pthread_t(pthread_t *check_thread,
						t_philo *philo);
void				ft_destroy_check_pthread_t(pthread_t *check_thread,
						t_philo *table);

t_sem				*ft_init_t_sem(t_args *args);
void				ft_unlink_t_sem(void);
void				ft_destroy_t_sem(t_sem *sem);
t_sem				*ft_open_t_sem(t_sem *sem, t_args *args);

void				ft_lock_sem_t(sem_t *sem, int count);

void				ft_free_t_args(t_args *args);

#endif
