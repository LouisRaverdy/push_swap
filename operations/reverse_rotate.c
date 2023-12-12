/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:22:19 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/05 15:00:51 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	last = get_stack_last(*stack);
	before_last = get_stack_before_last(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
