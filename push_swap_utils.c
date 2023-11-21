/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:11 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/21 16:08:31 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int number, t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while(!temp)
	{
		if (temp->value == number)
			return (1);
		else
			temp = temp->next;
	}
	return (0);
}

void	free_exit_error(t_list *stack)
{
	free_stack(stack);
	exit_error();
}

void	exit_error()
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while(!stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
