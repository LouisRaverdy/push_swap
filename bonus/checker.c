/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:43 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/13 15:50:13 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	dispatcher_instruction(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	int	valid;

	valid = 0;
	if (!cmd)
		return (0);
	if (!ft_strncmp(cmd, "rra\n", 4))
	{
		reverse_rotate(stack_a);
		valid = 1;
	}
	if (!ft_strncmp(cmd, "ss\n", 3))
	{
		swap(stack_a);
		swap(stack_b);
		valid = 1;
	}
	sub_dispatcher1(stack_a, stack_b, cmd, &valid);
	sub_dispatcher2(stack_a, stack_b, cmd, &valid);
	if (valid == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		check;
	char	*cmd;
	int		error;
	t_stack	*stack_b;
	t_stack	*stack_a;

	stack_a = create_stack(argv + 1);
	stack_b = NULL;
	set_stack_index(stack_a, get_stack_size(stack_a) + 1);
	error = 0;
	check = 0;
	while (!check)
	{
		cmd = get_next_line(0);
		if (is_valid(cmd) &&
			dispatcher_instruction(&stack_a, &stack_b, cmd))
			error = 1;
		if (error || !cmd)
			write_indicator(&stack_a, &stack_b, &error, &check);
		if (!cmd)
			free(cmd);
	}
	if (error == 1)
		return (84);
	return (0);
}
