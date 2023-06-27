/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:32:11 by ael-kace          #+#    #+#             */
/*   Updated: 2023/06/26 19:18:06 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_make_action(long action)
{
	long	begin;

	begin = ft_time();
	while (ft_time() - begin < action)
		usleep(50);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->inf_data->print);
	printf("%ld  %d %s\n", ft_time(), philo->id_philo, str);
	pthread_mutex_unlock(&philo->inf_data->print);
}

void	get_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->time);
}

void	check_nb_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->inf_data->action);
	if (philo->nb_meal > 0)
	{
		philo->nb_meal--;
	}
	pthread_mutex_unlock(&philo->inf_data->action);
}

void	*routin(void *rou)
{
	t_philo	*philo;

	philo = (t_philo *)rou;
	if (philo->id_philo % 2 == 0)
		usleep(150);
	while (1)
	{
		pthread_mutex_lock(&philo->forks);
		ft_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->next->forks);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		get_time(philo);
		ft_is_make_action(philo->num_of_eat);
		pthread_mutex_unlock(&philo->forks);
		pthread_mutex_unlock(&philo->next->forks);
		ft_print(philo, "is sleeping");
		ft_is_make_action(philo->num_of_sleep);
		ft_print(philo, "is thinking");
		check_nb_meal(philo);
	}
	return (NULL);
}
