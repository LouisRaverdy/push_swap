/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraverdy <lraverdy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:35:45 by lraverdy          #+#    #+#             */
/*   Updated: 2023/12/07 17:20:46 by lraverdy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;
	char	prev_char;

	i = 0;
	words = 0;
	prev_char = c;
	while (s && s[i])
	{
		if (prev_char == c && s[i] != c)
			words++;
		prev_char = s[i];
		i++;
	}
	return (words);
}

static void	ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*ft_word_dup(const char *str, int start, int finish, char	**array)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (word == NULL)
	{
		ft_free_array(array);
		return (NULL);
	}
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split_return(char **array, int j)
{
	array[j] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c, t_stack **stack)
{
	size_t	i;
	int		j;
	int		valid;
	char	**array;

	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		free_exit_error(stack);
	i = 0;
	j = 0;
	valid = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && valid < 0)
			valid = i;
		else if ((s[i] == c || i == ft_strlen(s)) && valid >= 0)
		{
			array[j] = ft_word_dup(s, valid, i, array);
			if (array[j++] == NULL)
				return (NULL);
			valid = -1;
		}
		i++;
	}
	return (ft_split_return(array, j));
}
