/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:24 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/21 15:52:42 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>

typedef struct		s_list
{
	int				value;
	int				index;
	int				coast_a;
	int				coast_b;
	int				pos;
	int				target_pos;
	struct s_list	*next;
}					t_list;

// Libft Utils
int		ft_atoi(char *str, t_list *stack);

// Utils
void	exit_error();
void	free_stack(t_list *stack);
void	free_exit_error(t_list *stack);
int		check_double(int number, t_list *stack);

#endif
