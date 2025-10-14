#include "philosophers.h"

void	fn_destroy_mutexes(t_philo *philo)
{
	int	id;

	id = 0;
	while (id < NB_PHILO)
	{
		pthread_mutex_destroy(&(philo[id].fork));
		id++;
	}
	pthread_mutex_destroy(&philo->context->death_mutex);
	pthread_mutex_destroy(&philo->context->print_mutex);
	pthread_mutex_destroy(&philo->context->satiation_mutex);
	pthread_mutex_destroy(&philo->context->last_meal_mutex);
}

void	fn_cleanup_data(t_philo *philos)
{
	fn_destroy_mutexes(philos);
	free(philos);
}

void	fn_free_and_exit(char *msg, t_philo *philos)
{
	if (philos)
		fn_cleanup_data(philos);
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	fn_join_threads(pthread_t banshee, t_philo *philos)
{
	int	id;

	if (philos->context->nb_of_philos > 1)
		if (banshee)
			pthread_join(banshee, NULL);
	if (philos)
	{
		id = 0;
		while (id < philos->context->nb_of_philos)
		{
			pthread_join(philos[id].thread, NULL);
			id++;
		}
	}
}
