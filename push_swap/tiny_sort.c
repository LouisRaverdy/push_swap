/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:34 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/28 14:10:39 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	tiny_sort(t_stack *stack)
{
	int		highest;

	highest = find_highest_index(stack);
	if (stack->index == highest)
		do_ra(stack);
	else if (stack->next->index == highest)
		do_rra(stack);
	if (stack->index > stack->next->index)
		do_sa(stack);
}
