/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:09 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/27 15:23:39 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*node;

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

void	stack_split(char **tab, t_stack **stack, t_stack **head, int first)
{
	size_t	i;

	i = 0;
	if (first)
		i++;
	while (tab && tab[i])
	{
		(*head)->next = create_node(ft_atoi(0, tab[i], stack, tab));
		if (!(*head)->next)
		{
			ft_free_array(tab);
			free_exit_error(stack);
		}
		(*head) = (*head)->next;
		i++;
	}
}

t_stack	*create_stack(char **array)
{
	size_t	i;
	t_stack	*stack;
	t_stack	*head;
	char	**splited;

	i = 1;
	stack = create_node(0);
	if (!stack)
		exit_error();
	head = stack;
	splited = ft_split(array[0], ' ', &stack);
	if (!splited)
		free_exit_error(&stack);
	head->value = ft_atoi(1, splited[0], &stack, splited);
	stack_split(splited, &stack, &head, 1);
	ft_free_array(splited);
	while (array[i])
	{
		splited = ft_split(array[i++], ' ', &stack);
		if (!splited)
			free_exit_error(&stack);
		stack_split(splited, &stack, &head, 0);
		ft_free_array(splited);
	}
	return (stack);
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
		return (0);
	stack_a = create_stack(argv + 1);
	stack_b = NULL;
	stack_size = get_stack_size(stack_a);
	set_stack_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
