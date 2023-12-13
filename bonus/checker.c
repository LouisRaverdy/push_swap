/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:43 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/13 17:18:09 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid_cmd(char *cmd)
{
	if (cmd == "rra" || cmd == "rrb" || cmd == "rrr")
		return (1);
	if (cmd == "sa" || cmd == "sb" || cmd == "ss")
		return (1);
	if (cmd == "ra" || cmd == "rb" || cmd == "rr")
		return (1);
	if (cmd == "pa" || cmd == "pb")
		return (1);
}

int	dispatcher_instruction(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "rra\n"))
		reverse_rotate(stack_a);
	if (!ft_strcmp(cmd, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (!ft_strcmp(cmd, "ra\n", 3))
	{
		rotate(stack_a);
	}
	if (!ft_strcmp(cmd, "rb\n", 3))
		rotate(stack_b);
	if (!ft_strcmp(cmd, "rr\n", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (!ft_strcmp(cmd, "rrr\n", 4))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	sub_dispatcher_bis(stack_a, stack_b, cmd);
	return (0);
}

void	sub_dispatcher_bis(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		push(stack_b, stack_a);
	if (!ft_strncmp(cmd, "pb\n", 3))
		push(stack_a, stack_b);
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap(stack_a);
	if (!ft_strncmp(cmd, "sb\n", 3))
		swap(stack_b);
	if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate(stack_b);
}

void	write_indicator(t_stack **stack_a, t_stack **stack_b,
	int *error, int *check)
{
	close(0);
	get_next_line(0);
	if (is_sorted(stack_a, stack_b) && !(*error))
		ft_putstr("OK\n");
	else if (*error)
		ft_putstr("Error\n");
	else
	{
		ft_putstr("KO\n");
		*error = 1;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	*check = 1;
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
	while (!check && !error)
	{
		cmd = get_next_line(0);
		if (is_valid_cmd(cmd) && !cmd &&
			dispatcher_instruction(&stack_a, &stack_b, cmd))
			error = 1;
		if (error || !cmd)
			write_indicator(&stack_a, &stack_b, &error, &check);
		if (!cmd)
			free(cmd);
	}
	if (error)
		exit(EXIT_FAILURE);
	return (0);
}
