#include "philosophers.h"

bool	fn_is_philo_satiated(t_context *context, t_philo *philo)
{
	pthread_mutex_lock(&(context->satiation_mutex));
	if (philo->is_satiated)
	{
		pthread_mutex_unlock(&(context->satiation_mutex));
		return (true);
	}
	pthread_mutex_unlock(&(context->satiation_mutex));
	return (false);
}

bool	fn_is_philo_dead(t_context *context)
{
	long	time_now;
	long	time_since_last_meal;
	long	time_to_die;
	int		id;

	id = 0;
	while (id < context->nb_of_philos)
	{
		if (fn_is_philo_satiated(context, &context->philos[id]))
		{
			id++;
			continue ;
		}
		time_now = fn_get_epoch_in_msec();
		pthread_mutex_lock(&(context->last_meal_mutex));
		time_since_last_meal = time_now - context->philos[id].time_of_last_meal;
		pthread_mutex_unlock(&(context->last_meal_mutex));
		time_to_die = context->time_to_die;
		if (time_since_last_meal > time_to_die)
		{
			fn_keening(context, id, time_now);
			return (true);
		}
		id++;
	}
	return (false);
}

void	fn_keening(t_context *context, int id, long timestamp)
{
	pthread_mutex_lock(&(context->death_mutex));
	context->is_dead = true;
	pthread_mutex_unlock(&(context->death_mutex));
	printf("%lu %i died\n", timestamp - context->time_of_start, id);
}

bool	fn_all_satiated(t_context *context)
{
	bool	res;

	pthread_mutex_lock(&(context->satiation_mutex));
	if (context->nb_of_philos_satiated == context->nb_of_philos)
		res = true;
	else
		res = false;
	pthread_mutex_unlock(&(context->satiation_mutex));
	return (res);
}
