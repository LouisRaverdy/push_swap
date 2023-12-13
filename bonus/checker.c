/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:43 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/12 17:41:37 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		check;
	char	*cmd;
	int		error;
	t_stack	*stack_b;
	t_stack	*stack_a;

	error = 0;
	check = 0;
	init_stack(argc, argv, &stack_a, &stack_b);
	while (check == 0)
	{
		cmd = get_next_line(0);
		if (dispatcher_instruction(&stack_a, &stack_b, cmd))
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
