/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:42:11 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/27 16:57:28 by lraverdy         ###   ########.fr       */
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

void	init_vars(t_stack **stack_a, t_stack **stack_b,
			char **argv, int *error)
{
	if (argv[1] == NULL)
		exit_error();
	*stack_a = create_stack(argv + 1);
	*stack_b = NULL;
	set_stack_index(*stack_a, get_stack_size(*stack_a) + 1);
	*error = 0;
}
