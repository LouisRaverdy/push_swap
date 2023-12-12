/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:13:35 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/05 18:06:58 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_dest)
{
	t_stack	*temp;

	if ((*stack_from) == NULL)
		return ;
	temp = (*stack_from)->next;
	(*stack_from)->next = (*stack_dest);
	(*stack_dest) = (*stack_from);
	(*stack_from) = temp;
}

void	do_pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
