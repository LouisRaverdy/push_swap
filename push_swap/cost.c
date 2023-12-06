/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:47:31 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/06 23:02:22 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = get_stack_size(temp_a);
	size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->cost_b > size_b / 2)
			temp_b->cost_b = -1 * (size_b - temp_b->pos);
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = -1 * (size_a - temp_b->target_pos);
		temp_b = temp_b->next;
	}
}

static void	do_operation_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(stack_a);
			(*cost_a)++;
		}
	}
}

static void	do_operation_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	exec_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr_max(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr_max(a, b, &cost_a, &cost_b);
	do_operation_b(b, &cost_b);
	do_operation_a(a, &cost_a);
	do_pa(b, a);
}

void	exec_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		cheap_cost_a;
	int		cheap_cost_b;
	int		cheapest_move;

	temp_b = *stack_b;
	cheapest_move = INT_MAX;
	while (temp_b)
	{
		if (abolute_value(temp_b->cost_a) + abolute_value(temp_b->cost_b) < cheapest_move)
		{
			cheapest_move = abolute_value(temp_b->cost_b) + abolute_value(temp_b->cost_a);
			cheap_cost_a = temp_b->cost_a;
			cheap_cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	exec_move(stack_a, stack_b, cheap_cost_a, cheap_cost_b);
}
