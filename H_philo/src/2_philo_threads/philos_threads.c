#include "philosophers.h"

bool	fn_check_for_deaths(t_philo *philo)
{
	pthread_mutex_lock(&(philo->context->death_mutex));
	if (philo->context->is_dead == true)
	{
		pthread_mutex_unlock(&(philo->context->death_mutex));
		return (false);
	}
	else
	{
		pthread_mutex_unlock(&(philo->context->death_mutex));
		return (true);
	}
}

void	*philos_routine(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *) philo_arg;
	while (true)
	{
		fn_try_to_eat(philo);
		if (fn_check_if_satiated(philo) || fn_check_for_deaths(philo))
			return (NULL);
		fn_sleep_and_think(philo);
		if (fn_check_for_deaths(philo))
			return (NULL);
	}
}

void	*one_philo_routine(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *) philo_arg;
	pthread_mutex_lock(&(OWN_FORK));
	fn_print_state(philo, "has taken a fork");
	fn_wrapper_usleep(philo->context->time_to_die);
	pthread_mutex_unlock(&(OWN_FORK));
	fn_print_state(philo, "is dead");
	pthread_exit(NULL);
}

bool	fn_philos_start_threads(t_philo *philos)
{
	int	i;

	i = 0;
	if (philos->context->nb_of_philos == 1)
	{
		if (pthread_create
			(&(philos[i].thread), NULL, one_philo_routine, &philos[i])
			!= EXIT_SUCCESS)
			return (false);
		return (true);
	}
	i = 0;
	while (i < philos->context->nb_of_philos)
	{
		if (pthread_create
			(&(philos[i].thread), NULL, philos_routine, &philos[i])
			!= EXIT_SUCCESS)
			return (false);
		i++;
	}
	return (true);
}
