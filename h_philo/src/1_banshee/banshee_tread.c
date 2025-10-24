#include "philosophers.h"

void	*banshee_routine(void *context_arg)
{
	t_context	*context;

	context = (t_context *) context_arg;
	while (true)
	{
		if (fn_all_satiated(context))
			return (NULL);
		if (fn_is_philo_dead(context))
			return (NULL);
	}
	return (NULL);
}

bool	fn_banshee_start_thread(pthread_t *banshee, t_context *context)
{
	if (pthread_create
		(banshee, NULL, banshee_routine, context)
		!= EXIT_SUCCESS)
	{
		return (false);
	}
	return (true);
}
