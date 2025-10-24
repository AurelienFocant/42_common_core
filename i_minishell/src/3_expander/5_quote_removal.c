/* ************************************************************************** */
/*                                                                            */
/*   5_quote_removal.c                                    :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:40:07 by afocant           #+#    #+#             */
/*   Updated: 2025/03/31 15:39:15 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tinyshell.h"

static void	copy_quote_mode(char *tmp, char *str, int *i, int *j)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[(*i)] != quote)
		tmp[(*j)++] = str[(*i)++];
	(*i)++;
}

static void	copy_without_quotes(char *tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\\')
		{
			i++;
			tmp[j++] = str[i++];
		}
		else if (is_quote(str[i]))
			copy_quote_mode(tmp, str, &i, &j);
		else
			tmp[j++] = str[i++];
	}
	tmp[j] = '\0';
}

void	quote_removal(char **s, t_shell *shell)
{
	char	*tmp;
	char	*str;
	char	*res;

	str = *s;
	tmp = malloc(ft_strlen(str) + 1);
	if (!tmp)
		free_and_exit_shell("Malloc failed", EXIT_FAILURE, shell);
	copy_without_quotes(tmp, str);
	res = ft_strdup(tmp);
	free(tmp);
	free(*s);
	*s = res;
}
