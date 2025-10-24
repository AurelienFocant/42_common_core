#include "philosophers.h"

bool	fn_setup_context(t_context *context, char **argv)
{
	if (pthread_mutex_init(&(context->death_mutex), NULL) != EXIT_SUCCESS)
		return (false);
	if (pthread_mutex_init(&(context->print_mutex), NULL) != EXIT_SUCCESS)
		return (false);
	if (pthread_mutex_init(&(context->satiation_mutex), NULL) != EXIT_SUCCESS)
		return (false);
	if (pthread_mutex_init(&(context->last_meal_mutex), NULL) != EXIT_SUCCESS)
		return (false);
	context->time_of_start = fn_get_epoch_in_msec();
	context->is_dead = false;
	context->nb_of_philos = ft_atoi(argv[1]);
	context->time_to_die = ft_atoi(argv[2]);
	context->time_to_eat = ft_atoi(argv[3]);
	context->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		context->total_nb_of_meals = ft_atoi(argv[5]);
	else
		context->total_nb_of_meals = -1;
	context->nb_of_philos_satiated = 0;
	return (true);
}

t_philo	*fn_init_philos(t_context *context)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * context->nb_of_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < context->nb_of_philos)
	{
		if (pthread_mutex_init(&(philos[i].fork), NULL) != EXIT_SUCCESS)
		{
			free(philos);
			return (NULL);
		}
		philos[i].id = i;
		philos[i].time_of_last_meal = fn_get_epoch_in_msec();
		philos[i].meals_eaten = 0;
		philos[i].context = context;
		i++;
	}
	philos->context->philos = philos;
	return (philos);
}
