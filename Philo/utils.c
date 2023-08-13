/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:05 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/12 20:49:09 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_arg_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[++j])
		{
			if (!check_arg_digit(av[j]))
				return (0);
		}
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	else
		return (result * sign);
}

long	ft_time(void)
{
	struct timeval	time;
	long			current_time;
	static long		start;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (!start)
		start = current_time; 
	return (current_time - start);
}

// long	ft_time_d(void)
// {
// 	struct timeval	time;
// 	long			current_time;
// 	static long		start;

// 	gettimeofday(&time, NULL);
// 	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
// 	if (!start)
// 		start = current_time;
// 	return (current_time);
// }
