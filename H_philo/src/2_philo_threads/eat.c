#include "philosophers.h"

void	fn_lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(OWN_FORK));
		fn_print_state(philo, "picked up own fork");
		pthread_mutex_lock(&(LEFT_FORK));
		fn_print_state(philo, "picked up other fork");
	}
	else
	{
		pthread_mutex_lock(&(LEFT_FORK));
		fn_print_state(philo, "picked up other fork");
		pthread_mutex_lock(&(OWN_FORK));
		fn_print_state(philo, "picked up own fork");
	}
}

void	fn_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(OWN_FORK));
	pthread_mutex_unlock(&(LEFT_FORK));
}

void	fn_eat(t_philo *philo)
{
	fn_print_state(philo, "is eating");
	philo->meals_eaten += 1;
	fn_wrapper_usleep(philo->context->time_to_eat);
}

bool	fn_check_if_satiated(t_philo *philo)
{
	bool res;

	pthread_mutex_lock((&philo->context->last_meal_mutex));
	if (philo->meals_eaten == philo->context->total_nb_of_meals)
	{
		pthread_mutex_lock(&(philo->context->satiation_mutex));
		philo->is_satiated = true;
		philo->context->nb_of_philos_satiated++;
		pthread_mutex_unlock(&(philo->context->satiation_mutex));
		res = true;
	}
	else
		res = false;
	pthread_mutex_unlock((&philo->context->last_meal_mutex));
	return (res);
}

bool fn_check_if_dead(t_philo *philo)
{
	bool	res;

	pthread_mutex_lock(&(philo->context->death_mutex));
	if (philo->context->is_dead == true)
		res = true;
	else
		res = false;
	pthread_mutex_unlock(&(philo->context->death_mutex));
	return (res);
}

void	fn_try_to_eat(t_philo *philo)
{
	fn_lock_forks(philo);
	fn_update_time_last_meal(philo);
	fn_eat(philo);
	fn_unlock_forks(philo);
}
