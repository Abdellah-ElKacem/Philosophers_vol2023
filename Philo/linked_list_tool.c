/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:34 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/14 18:15:23 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int nbr, t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	pthread_mutex_init(&new->forks, NULL);
	pthread_mutex_init(&new->time, NULL);
	new->id_philo = nbr;
	new->last_meal = ft_time();
	new->num_of_die = data->num_die;
	new->num_of_eat = data->num_eat;
	new->num_of_sleep = data->num_sleep;
	new->nb_meal = data->num_rep_eat;
	new->flag = 0;
	new->inf_data = data;
	new->next = NULL;
	return (new);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	last = ft_lstlast(*alst);
	if (!last)
		*alst = new;
	last->next = new;
}
