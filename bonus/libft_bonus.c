/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:42:11 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/15 01:55:52 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

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

void	stack_split(char **tab, t_stack **stack, t_stack **head)
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
	t_stack	*stack;
	t_stack	*head;
	char	**splited;

	i = 0;
	stack = create_node(0);
	if (!stack)
		exit_error();
	head = stack;
	splited = ft_split(array[i++], ' ', &stack);
	head->value = ft_atoi(1, splited[0], &stack);
	stack_split(splited + 1, &stack, &head);
	free_split(splited);
	while (array[i])
	{
		splited = ft_split(array[i], ' ', &stack);
		stack_split(splited, &stack, &head);
		free_split(splited);
		i++;
	}
	return (stack);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[index] != '\0' && s2[index] != '\0' && s1[index] == s2[index])
		index++;
	if (s1[index] != s2[index])
		return (0);
	else
		return (1);
}
