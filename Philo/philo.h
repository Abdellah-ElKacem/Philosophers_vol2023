/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kace <ael-kace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:41:21 by ael-kace          #+#    #+#             */
/*   Updated: 2023/08/14 18:04:29 by ael-kace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	forks;
	pthread_mutex_t	time;
	int				id_philo;
	long			last_meal;
	int				flag;
	long			num_of_die;
	long			num_of_eat;
	long			num_of_sleep;
	long			nb_meal;
	pthread_t		philo_t;
	struct s_philo	*next;
	struct s_data	*inf_data;
}				t_philo;

typedef struct s_data
{
	int				num_philo;
	int				flag_meal;
	long			num_die;
	long			num_eat;
	long			num_sleep;
	long			num_rep_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	action;
	struct s_philo	*inf_philo;
}				t_data;

/*Parsing*/

t_philo	*ft_lstnew(int nbr, t_data *data);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
int		check_digit(int ac, char **av);
long	ft_atoi(const char *str);
void	creaton_thread(t_philo *inf_philo, t_data *data);
void	*routin(void *rou);
long	ft_time(void);
void	ft_print(t_philo *philo, char *str);
int		check_death(t_philo *philo);
void	ft_is_make_action(long action);

#endif