/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:14:52 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/28 14:37:16 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
