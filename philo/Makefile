NAME = philo

SRCS =	main.c\
		\
		action.c\
		check.c\
		ft_free.c\
		ft_init_table.c\
		ft_atoi.c\
		ft_philosopher.c\
		ft_pthread_t_utils.c\
		ft_simulation.c\
		ft_t_global_utils.c\
		ft_t_philo_utils.c\
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