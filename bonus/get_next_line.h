/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:09:00 by lraverdy          #+#    #+#             */
/*   Updated: 2023/10/26 14:22:20 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *src);
char	*ft_new_left_str(char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);

#endif
