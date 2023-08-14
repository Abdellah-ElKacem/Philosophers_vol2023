/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:40 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/14 17:48:23 by ael-kace         ###   ########.fr       */
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
		if (inf_philo->id_philo % 2 == 0)
			usleep(100);
		pthread_create(&inf_philo->philo_t, NULL, &routin, inf_philo);
		pthread_detach(inf_philo->philo_t);
		usleep(150);
		inf_philo = inf_philo->next;
	}
	if (check_death(inf_philo) > 0)
		return ;
	usleep(150);
}
