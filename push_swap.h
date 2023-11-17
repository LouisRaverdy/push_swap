/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:24 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/17 13:54:11 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>

typedef struct		s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

// Libft Utils
int		ft_atoi(char *str, t_list *stack);

// Utils
void	exit_error();
void	free_stack(t_list *stack);

#endif
