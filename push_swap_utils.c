/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:11 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/17 13:53:14 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
