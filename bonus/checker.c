/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:43 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/27 16:57:04 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	is_valid_cmd(char *cmd, int *error, int argc)
{
	(void)argc;
	if (ft_strcmp(cmd, "rra\n") || ft_strcmp(cmd, "rrb\n"))
		(*error) = 0;
	else if (ft_strcmp(cmd, "rrr\n") || ft_strcmp(cmd, "ss\n"))
		(*error) = 0;
	else if (ft_strcmp(cmd, "sa\n") || ft_strcmp(cmd, "sb\n"))
		(*error) = 0;
	else if (ft_strcmp(cmd, "ra\n") || ft_strcmp(cmd, "rb\n"))
		(*error) = 0;
	else if (ft_strcmp(cmd, "rr\n") || ft_strcmp(cmd, "pa\n"))
		(*error) = 0;
	else if (ft_strcmp(cmd, "pb\n") || cmd == NULL)
		(*error) = 0;
	else
		(*error) = 1;
}

void	sub_dispatcher_bis(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (ft_strcmp(cmd, "pa\n"))
		push(stack_b, stack_a);
	if (ft_strcmp(cmd, "pb\n"))
		push(stack_a, stack_b);
	if (ft_strcmp(cmd, "sa\n"))
		swap(stack_a);
	if (ft_strcmp(cmd, "sb\n"))
		swap(stack_b);
	if (ft_strcmp(cmd, "rrb\n"))
		reverse_rotate(stack_b);
}

void	dispatcher_instruction(t_stack **stack_a, t_stack **stack_b, char *cmd)
{
	if (ft_strcmp(cmd, "rra\n"))
		reverse_rotate(stack_a);
	if (ft_strcmp(cmd, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (ft_strcmp(cmd, "ra\n"))
	{
		rotate(stack_a);
	}
	if (ft_strcmp(cmd, "rb\n"))
		rotate(stack_b);
	if (ft_strcmp(cmd, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (ft_strcmp(cmd, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	sub_dispatcher_bis(stack_a, stack_b, cmd);
}

void	write_indicator(t_stack **stack_a, t_stack **stack_b,
	int *error, int *check)
{
	close(0);
	get_next_line(0);
	if (is_sorted(stack_a, stack_b) && !(*error))
		ft_putstr("OK\n");
	else if (*error)
		write(2, "Error\n", 6);
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

	init_vars(&stack_a, &stack_b, argv, &error);
	check = 0;
	while (!check && !error)
	{
		cmd = get_next_line(0);
		is_valid_cmd(cmd, &error, argc);
		if (cmd && !error)
			dispatcher_instruction(&stack_a, &stack_b, cmd);
		else
			write_indicator(&stack_a, &stack_b, &error, &check);
		if (cmd)
			free(cmd);
	}
	if (error)
		exit(EXIT_FAILURE);
	return (0);
}
