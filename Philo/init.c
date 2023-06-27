/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:20:07 by ael-kace          #+#    #+#             */
/*   Updated: 2023/06/26 19:46:35 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*creation_list(t_philo *inf_philo, t_data *data)
{
	t_philo	*begin;
	int		i;

	i = 0;
	while (++i <= data->num_philo)
	{
		if (!inf_philo)
			inf_philo = ft_lstnew(i, data);
		else
			ft_lstadd_back(&inf_philo, ft_lstnew(i, data));
	}
	if (!inf_philo)
		return (write(1, "Error : malloc !", 17), NULL);
	begin = inf_philo;
	inf_philo = ft_lstlast(inf_philo);
	inf_philo->next = begin;
	return (begin);
}

void	creaton_thread(t_philo *inf_philo, t_data *data)
{
	int	i;

	i = -1;
	inf_philo = creation_list(inf_philo, data);
	if (!inf_philo || !data)
		return ;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->action, NULL);
	while (++i < data->num_philo)
	{
		inf_philo->last_meal = ft_time();
		pthread_create(&inf_philo->philo_t, NULL, &routin, inf_philo);
		inf_philo = inf_philo->next;
		pthread_detach(inf_philo->philo_t);
	}
	check_death(inf_philo);
	ft_is_make_action(5);
}
