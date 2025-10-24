#ifndef PROTOTYPES_PHILOSOPHERS_H
# define PROTOTYPES_PHILOSOPHERS_H

#include "philosophers.h"

/*----------------  src/4_general_utils  ---------------*/
/* File: init.c */
bool	fn_setup_context(t_context *context, char **argv);
t_philo	*fn_init_philos(t_context *context);

/* File: args_checking.c */
bool	fn_check_nb_of_args(int argc);
bool	fn_check_args_only_digits(char **argv);
bool	fn_check_args_not_zero(char **argv);
bool	fn_check_args(int argc, char **argv);

/* File: cleanup.c */
void	fn_destroy_mutexes(t_philo *philo);
void	fn_cleanup_data(t_philo *philos);
void	fn_free_and_exit(char *msg, t_philo *philos);
void	fn_join_threads(pthread_t banshee, t_philo *philos);

/* File: ft_atoi.c */
int	ft_isdigit(int c);
int	ft_is_a_space(char c);
int	ft_atoi(const char *str);


/*----------------  src/2_philo_threads  ---------------*/
/* File: sleep_think_print.c */
void	fn_print_state(t_philo *philo, char *msg);
void	fn_wrapper_usleep(long time_in_msec);
void	fn_sleep_and_think(t_philo *philo);

/* File: philos_threads.c */
bool	fn_check_for_deaths(t_philo *philo);
void	*philos_routine(void *philo_arg);
void	*one_philo_routine(void *philo_arg);
bool	fn_philos_start_threads(t_philo *philos);

/* File: eat.c */
void	fn_lock_forks(t_philo *philo);
void	fn_unlock_forks(t_philo *philo);
void	fn_eat(t_philo *philo);
bool	fn_check_if_satiated(t_philo *philo);
bool fn_check_if_dead(t_philo *philo);
void	fn_try_to_eat(t_philo *philo);


/*----------------  src  ---------------*/
/* File: 0_main.c */


/*----------------  src/1_banshee  ---------------*/
/* File: check_death.c */
bool	fn_is_philo_satiated(t_context *context, t_philo *philo);
bool	fn_is_philo_dead(t_context *context);
void	fn_keening(t_context *context, int id, long timestamp);
bool	fn_all_satiated(t_context *context);

/* File: banshee_tread.c */
void	*banshee_routine(void *context_arg);
bool	fn_banshee_start_thread(pthread_t *banshee, t_context *context);


/*----------------  src/3_timestamps_utils  ---------------*/
/* File: timestamp_utils.c */
void	fn_update_time_last_meal(t_philo *philo);
long	fn_get_timestamp(t_philo *philo, int mode);
long	fn_get_epoch_in_msec(void);

#endif
