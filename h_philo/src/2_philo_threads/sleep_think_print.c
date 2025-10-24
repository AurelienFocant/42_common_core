#include "philosophers.h"

void	fn_print_state(t_philo *philo, char *msg)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&(philo->context->print_mutex));
	timestamp = fn_get_timestamp(philo, PHILO);
	if (timestamp)
		printf("%lu philo nb %i %s\n", timestamp, philo->id, msg);
	else
		printf("prout");
	pthread_mutex_unlock(&(philo->context->print_mutex));
}

void	fn_wrapper_usleep(long time_in_msec)
{
	long	time_now;

	time_now = fn_get_epoch_in_msec();
	while (fn_get_epoch_in_msec() - time_now < time_in_msec)
		usleep(100);
}

void	fn_sleep_and_think(t_philo *philo)
{
	fn_print_state(philo, "is sleeping");
	fn_wrapper_usleep(philo->context->time_to_sleep);
	fn_print_state(philo, "is thinking");
}
