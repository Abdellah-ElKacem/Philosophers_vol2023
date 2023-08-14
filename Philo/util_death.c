/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:40:52 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/14 18:17:04 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nbr_meal(t_philo *philo)
{
	if (philo->nb_meal == 0 && philo->flag == 0)
	{
		philo->flag++;
		philo->inf_data->flag_meal++;
	}
	if (philo->inf_data->flag_meal >= philo->inf_data->num_philo)
		return (1);
	else
		return (0);
}

int	check_death(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->time);
		if (ft_time() - philo->last_meal > philo->num_of_die)
		{
			pthread_mutex_unlock(&philo->time);
			pthread_mutex_lock(&philo->inf_data->print);
			printf("%ld  %d %s\n", ft_time(), philo->id_philo, "died");
			return (0);
		}
		pthread_mutex_lock(&philo->inf_data->action);
		if (check_nbr_meal(philo) == 1)
		{
			pthread_mutex_unlock(&philo->inf_data->action);
			pthread_mutex_lock(&philo->inf_data->print);
			break ;
		}
		pthread_mutex_unlock(&philo->inf_data->action);
		pthread_mutex_unlock(&philo->time);
		philo = philo->next;
	}
	return (1);
}
