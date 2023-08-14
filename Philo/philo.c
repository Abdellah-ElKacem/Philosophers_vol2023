/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:28 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/14 18:04:42 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_arg(int ac, char **av, t_data *data)
{
	data->num_philo = ft_atoi(av[1]);
	data->num_die = ft_atoi(av[2]);
	data->num_eat = ft_atoi(av[3]);
	data->num_sleep = ft_atoi(av[4]);
	data->flag_meal = 0;
	if (ac == 6)
		data->num_rep_eat = ft_atoi(av[5]);
	else
		data->num_rep_eat = -1;
	return (1);
}

int	main(int ac, char **av)
{
	t_data	info;
	t_philo	*philo;

	philo = NULL;
	if (ac != 5 && ac != 6)
		return (write(1, "Error : Bad argumments !", 25), 0);
	if (check_digit(ac, av) == 0)
		return (write(1, "Error : Invalid Arg !", 22), 0);
	if (!put_arg(ac, av, &info))
		return (write(1, "Error : Invalid Number !", 25), 0);
	if (!info.num_philo)
		return (0);
	creaton_thread(philo, &info);
	return (0);
}
