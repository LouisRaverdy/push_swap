/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:15:03 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/05 16:14:00 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_max(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while ((*cost_a) > 0 && (*cost_b) > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

void	do_rrr_max(t_stack **stack_a, t_stack **stack_b,
	int *cost_a, int *cost_b)
{
	while ((*cost_a) < 0 && (*cost_b) < 0)
	{
		(*cost_b)++;
		(*cost_a)++;
		do_rrr(stack_a, stack_b);
	}
}
