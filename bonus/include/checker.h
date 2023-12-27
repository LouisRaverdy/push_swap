/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:01:24 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/27 16:58:30 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

// Get Next Line
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);

void	init_vars(t_stack **stack_a, t_stack **stack_b,
			char **argv, int *error);

#endif
