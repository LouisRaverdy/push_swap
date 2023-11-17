/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:09 by lraverdy          #+#    #+#             */
/*   Updated: 2023/11/17 13:56:47 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *create_node(int content)
{
	t_list *node;
	node = malloc(sizeof(size_t));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list *create_stack(char **array)
{
	size_t	i;
	t_list *stack;
	t_list *head;

	i = 0;
	stack = create_node(0);
	if (!stack)
		exit_error();
	stack->content = ft_atoi(array[i++], stack);
	head = stack;
	while (array[i])
	{
		head->next = create_node(ft_atoi(array[i++], stack));
		if (!head)
		{
			free_stack(stack);
			exit_error();
		}
		head = head ->next;
	}
	return (stack);
}

int main(int argc, char **argv)
{
	t_list *stack_a;

	if (argc < 2)
		exit_error(stack_a);

	stack_a = create_stack(argv + 1);
}
