#include "philo_bonus.h"

static int	ft_char_is_space(char symbol)
{
	if (symbol == ' ' || symbol == '\t' || symbol == '\n'
		|| symbol == '\r' || symbol == '\f' || symbol == '\v')
		return (1);
	return (0);
}

static unsigned int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_unsigned_representable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' || i == 0)
		return (0);
	if (ft_strlen(str) >= 10 && ft_strcmp(str, "2147483647") > 1)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (ft_char_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
		return (num);
	return (-1);
}
