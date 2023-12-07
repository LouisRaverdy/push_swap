/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:09 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/07 17:22:26 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int content)
{
	t_stack *node;
	node = malloc(sizeof * node);
	if (!node)
		return (NULL);
	node->value = content;
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}


void	stack_split(char **tab, t_stack **stack,t_stack **head)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		(*head)->next = create_node(ft_atoi(0, tab[i], stack));
		if (!(*head)->next)
		{

			free_stack(stack);
			exit_error();
		}
		(*head) = (*head)->next;
		i++;
	}

}

t_stack	*create_stack(char **array)
{
	size_t	i;
	t_stack *stack;
	t_stack *head;
	char	**splited;

	i = 0;
	stack = create_node(0);
	if (!stack)
		exit_error();
	head = stack;
	splited = ft_split(array[i++], ' ', &stack);
	head->value = ft_atoi(1, splited[0], &stack);
	stack_split(splited+1, &stack, &head);
	free_split(splited);
	while (array[i])
	{
		splited = ft_split(array[i], ' ',  &stack);
		stack_split(splited, &stack, &head);
		free_split(splited);
		i++;
	}
	return (stack);
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

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (is_sorted(stack_a, stack_b))
		return ;
	if (stack_size == 2)
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		exit_error();

	stack_a = create_stack(argv + 1);
	stack_b = NULL;
	stack_size = get_stack_size(stack_a);
	set_stack_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
