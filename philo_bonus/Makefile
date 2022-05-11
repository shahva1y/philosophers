NAME = philo_bonus

SRCS =	main.c\
		\
		table.c\
		action.c\
		check.c\
		error.c\
		ft_atoi.c\
		ft_free.c\
		ft_philosopher.c\
		ft_process_utils.c\
		ft_pthread_t_utils.c\
		ft_simulation.c\
		ft_t_philo_utils.c\
		ft_t_sem_utils.c\
		ft_t_args_utils.c\
		ft_timer.c\

OBJS = $(SRCS:%.c=%.o)
HEADER = philo.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

.PHONY	: all clean fclean re

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o		: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all