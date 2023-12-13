/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:24 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/12 16:33:33 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				pos;
	int				target_pos;
	struct s_stack	*next;
}					t_stack;

// Libft Utils
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_atoi(int first, char *str, t_stack **stack);

// Utils
void	exit_error(void);
void	free_stack(t_stack **stack);
void	free_exit_error(t_stack **stack);
int		get_stack_size(t_stack *stack);
int		check_double(long number, t_stack **stack);

// Utils Bis
int		is_sorted(t_stack **stack_a, t_stack **stack_b);
long	abolute_value(long number);
void	shift_stack(t_stack **stack);
t_stack	*get_stack_last(t_stack *stack);
t_stack	*get_stack_before_last(t_stack *stack);

// Tiny Sort
void	tiny_sort(t_stack **stack);

// Sort
void	sort(t_stack **stack_a, t_stack **stack_b);
void	set_stack_index(t_stack *stack, int stack_size);

// Max Move
void	do_rr_max(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	do_rrr_max(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);

// Swap
void	swap(t_stack **stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

// Rotate
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

// Push
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

// Reverse Rotate
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

// Position
void	get_position(t_stack **stack);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
int		get_lowest_index(t_stack **stack);

// Cost
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	exec_cheapest_move(t_stack **stack_a, t_stack **stack_b);

// FT Split
char	**ft_split(const char *s, char c, t_stack **stack);
void	free_split(char **tab);

#endif
