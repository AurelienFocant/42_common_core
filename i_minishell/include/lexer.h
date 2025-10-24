/* ************************************************************************** */
/*                                                                            */
/*   lexer.h                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: slangero <slangero@student.s19.be>           +:+ +:+         +:+     */
/*   By: afocant  <afocant@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:37:11 by afocant           #+#    #+#             */
/*   Updated: 2025/02/27 12:14:05 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tk_type
{
	SEMICOLON,
	LEFT_PAREN, RIGHT_PAREN,
	GREAT, LESS, D_GREAT, D_LESS,
	AMPERSAND, OR, D_AND, D_OR,
	WORD,
	EOL
}	t_tk_type;

typedef struct s_token
{
	t_tk_type		type;
	char			*lexeme;
	struct s_token	*next;
}	t_token;

#endif
