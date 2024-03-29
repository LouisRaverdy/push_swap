/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:22:19 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/15 02:01:15 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack)
		return ;
	last = get_stack_last(*stack);
	before_last = get_stack_before_last(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr\n");
}
