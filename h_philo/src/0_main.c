#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_context	context;
	t_philo		*philos;
	pthread_t	banshee;

	// weird error checking on locking forks !!
	if (!fn_check_args(argc, argv))
		return (EXIT_FAILURE);
	if (!fn_setup_context(&context, argv))
		return (EXIT_FAILURE);
	philos = fn_init_philos(&context);
	if (!philos)
		return (EXIT_FAILURE);
	if (context.nb_of_philos > 1)
	{
		if (!fn_banshee_start_thread(&banshee, &context))
		{
			fn_cleanup_data(philos);
			return (EXIT_FAILURE);
		}
	}
	if (!fn_philos_start_threads(philos))
	{
		fn_cleanup_data(philos);
		return (EXIT_FAILURE);
	}
	fn_join_threads(banshee, philos);
	fn_cleanup_data(philos);
	return (EXIT_SUCCESS);
}
