/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 09:57:37 by ael-kace          #+#    #+#             */
/*   Updated: 2023/06/26 19:51:47 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->time);
		if (ft_time() - philo->last_meal > philo->num_of_die)
		{
			pthread_mutex_lock(&philo->inf_data->print);
			printf("%ld  %d %s\n", ft_time(), philo->id_philo, "died");
			break ;
		}
		pthread_mutex_lock(&philo->inf_data->action);
		if (philo->nb_meal == 0)
		{
			pthread_mutex_lock(&philo->inf_data->print);
			return ;
		}
		pthread_mutex_unlock(&philo->inf_data->action);
		pthread_mutex_unlock(&philo->time);
		philo = philo->next;
	}
}
