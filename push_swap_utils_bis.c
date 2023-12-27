/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:46:04 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/05 16:36:00 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stack(t_stack **stack)
{
	t_stack	*temp_a;
	int		stack_size;
	int		lowest_index_pos;

	temp_a = *stack;
	stack_size = get_stack_size(temp_a);
	lowest_index_pos = get_lowest_index(stack);
	if (lowest_index_pos <= stack_size / 2)
	{
		while (lowest_index_pos > 0)
		{
			do_ra(stack);
			lowest_index_pos--;
		}
	}
	else
	{
		while (lowest_index_pos < stack_size)
		{
			do_rra(stack);
			lowest_index_pos++;
		}
	}
}

long	abolute_value(long number)
{
	if (number < 0)
		number = -number;
	return (number);
}

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	head = (*stack_a);
	if (*stack_b != NULL)
		return (0);
	while (head != NULL && head->next != NULL)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
