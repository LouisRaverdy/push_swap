/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:11 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/12 16:34:15 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(long number, t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	if (number > INT_MAX)
		return (1);
	while (temp)
	{
		if (temp->value == number)
			return (1);
		else
			temp = temp->next;
	}
	return (0);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	free_exit_error(t_stack **stack)
{
	free_stack(stack);
	exit_error();
}

void	exit_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
