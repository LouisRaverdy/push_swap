/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:19:17 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/07 17:19:42 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(int first, char *str, t_stack **stack)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i] || !str)
		free_exit_error(stack);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = (number * 10) + (str[i++] - '0');
		else
			free_exit_error(stack);
	}
	if (check_double(sign * number, stack) && !first)
		free_exit_error(stack);
	return (sign * number);
}
