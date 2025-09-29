/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:30:15 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 12:39:41 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_word_count(char *str, char *set)
{
	int	i;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] != '\0')
	{
		if (i > 0 && is_separator(str[i], set)
			&& !is_separator(str[i - 1], set))
			word_cnt++;
		i++;
	}
	if (i > 0 && !is_separator(str[i - 1], set))
		word_cnt++;
	return (word_cnt);
}

int	find_next_word(char *str, int *next_index, char *set)
{
	int	cnt_index;

	while (str[*next_index] != '\0' && is_separator(str[*next_index], set))
		(*next_index)++;
	cnt_index = *next_index;
	while (str[cnt_index] != '\0' && !is_separator(str[cnt_index], set))
		cnt_index++;
	return (cnt_index - *next_index);
}

void	populate(int word_cnt, char **splits, char *set, char *str)
{
	int		i;
	int		j;
	int		string_traverse;
	int		word_len;

	i = 0;
	string_traverse = 0;
	while (i < word_cnt)
	{
		word_len = find_next_word(str, &string_traverse, set);
		splits[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		j = 0;
		while (str[string_traverse] && !is_separator(str[string_traverse], set))
		{
			splits[i][j++] = str[string_traverse++];
		}
		splits[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	int		word_count;

	if (!str || !charset)
		return (NULL);
	word_count = get_word_count(str, charset);
	splits = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splits)
		return (NULL);
	populate(word_count, splits, charset, str);
	splits[word_count] = NULL;
	return (splits);
}
