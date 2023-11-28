/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:53:41 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/28 15:45:42 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

static int	get_best_position_bis(t_stack *temp_a, int target_index, int target_pos)
{
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

static int	get_best_position(t_stack **stack_a, int index_b)
{
	t_stack	*temp_a;
	int		target_index;
	int		target_pos;

	temp_a = (*stack_a);
	target_index = INT_MAX;
	target_pos = 0;
	while (temp_a)
	{
		if (temp_a->index > index_b && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	temp_a = (*stack_a)
	return (get_best_position_bis(temp_a, target_index, target_pos))
}



void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	temp_b = (*stack_b);
	get_position(stack_a);
	get_position(stack_b);
	while (temp_b)
	{
		temp_b->target_pos = get_best_position(stack_a, temp_b->index);
		temp_b = temp_b->next;
	}
}
