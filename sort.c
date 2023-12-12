/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:47:12 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/12 15:37:33 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	int		stack_size;
	int		nb_push;
	int		i;

	temp_a = (*stack_a);
	stack_size = get_stack_size(temp_a);
	nb_push = 0;
	i = 0;
	while (stack_size > 3 && i < stack_size && nb_push < stack_size / 2)
	{
		if ((*stack_a)->index >= (stack_size / 2))
		{
			do_pb(stack_a, stack_b);
			nb_push++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - nb_push > 3)
	{
		do_pb(stack_a, stack_b);
		nb_push++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_to_b(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b != NULL)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		exec_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a, stack_b))
		shift_stack(stack_a);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	set_stack_index(t_stack *stack, int stack_size)
{
	t_stack	*temp;
	t_stack	*highest;
	int		highest_value;

	while (stack_size-- > 0)
	{
		temp = stack;
		highest = NULL;
		highest_value = INT_MIN;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->value > highest_value && temp->index == 0)
			{
				highest = temp;
				highest_value = temp->value;
				temp = stack;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
