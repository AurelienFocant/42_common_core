/* ************************************************************************** */
/*                                                                            */
/*   tilde_exp.c                                          :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:40:35 by afocant           #+#    #+#             */
/*   Updated: 2025/04/01 13:52:29 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"
#include "expander.h"

static int	get_tilde_prefix(char *str)
{
	if (str[0] == '~')
	{
		if (!str[1] || ft_isspace(str[1]) || str[1] == '/')
			return (1);
		else if (str[1] == '-')
			return (2);
		else if (str[1] == '+')
			return (3);
		else
			return (0);
	}
	return (0);
}

static char	*join_val_to_str(char *val, char *str, int tilde_prefix, t_shell *shell)
{
	char	*res;
	size_t	len_tilde;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!tilde_prefix)
		len_tilde = 0;
	else if (tilde_prefix == TILDE_HOME)
		len_tilde = 1;
	else
		len_tilde = 2;
	len = ft_strlen(val) + ft_strlen(str) - len_tilde;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		free_and_exit_shell("Malloc failed\n", EXIT_FAILURE, shell);
	j = len_tilde;
	i = 0;
	while (*val)
		res[i++] = *val++;
	while (str[j])
		res[i++] = str[j++];
	res[i] = '\0';
	return (res);
}

void	tilde_expansion(char **s, t_shell *shell)
{
	int		tilde_prefix;
	char	*val;
	char	*res;

	tilde_prefix = get_tilde_prefix(*s);
	if (tilde_prefix == TILDE_HOME)
		val = ft_strdup(find_env_var_value("HOME", shell));
	else if (tilde_prefix == TILDE_PWD)
		val = ft_strdup(find_env_var_value("PWD", shell));
	else if (tilde_prefix == TILDE_OLDPWD)
		val = ft_strdup(find_env_var_value("OLDPWD", shell));
	else
		val = ft_strdup("");
	if (!val)
		free_and_exit_shell("Malloc failed\n", EXIT_FAILURE, shell);
	res = join_val_to_str(val, *s, tilde_prefix, shell);
	free(val);
	free(*s);
	*s = res;
}
