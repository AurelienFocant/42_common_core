#include "philosophers.h"

void	fn_update_time_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&(philo->context->last_meal_mutex));
	philo->time_of_last_meal = fn_get_epoch_in_msec();
	pthread_mutex_unlock(&(philo->context->last_meal_mutex));
}

long	fn_get_timestamp(t_philo *philo, int mode)
{
	long	timestamp;

	timestamp = fn_get_epoch_in_msec() - philo->context->time_of_start;
	if (mode == PHILO)
		if (!fn_check_for_deaths(philo))
			return (0);
	return (timestamp);
}

long	fn_get_epoch_in_msec(void)
{
	struct timeval	timeval;
	long			epoch;

	gettimeofday(&timeval, NULL);
	epoch = (timeval.tv_sec * 1000) + timeval.tv_usec / 1000;
	return (epoch);
}
