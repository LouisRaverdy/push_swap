/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:24 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/28 14:33:49 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <limits.h>

typedef struct		s_stack
{
	int				value;
	int				index;
	int				coast_a;
	int				coast_b;
	int				pos;
	int				target_pos;
	struct s_stack	*next;
}					t_stack;

// Libft Utils
int		ft_atoi(char *str, t_stack *stack);

// Utils
void	exit_error();
void	free_stack(t_stack *stack);
void	free_exit_error(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		check_double(int number, t_stack *stack);

// Utils Bis
int		is_sorted(t_stack *stack);
t_stack	*get_stack_last(t_stack *stack);
t_stack	*get_stack_before_last(t_stack *stack);

// Tiny Sort
void	tiny_sort(t_stack *stack);

// Swap
void	swap(t_stack *stack);
void	do_sa(t_stack *stack_a);
void	do_sb(t_stack *stack_b);
void	do_ss(t_stack *stack_a, t_stack *stack_b);

#endif
