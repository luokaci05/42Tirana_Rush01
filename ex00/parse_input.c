/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:25:23 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 12:51:47 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	is_valid_digit(char c)
{
	return (c >= '1' && c <= '4');
}

void	free_split(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
}

int	*populate_clues_array(char **splits, int *arr, int *cnt)
{
	int	i;

	i = 0;
	*cnt = 0;
	while (splits[i])
	{
		if (ft_strlen(splits[i]) != 1 || !is_valid_digit(splits[i][0]))
		{
			*cnt = -1;
			return (NULL);
		}
		arr[i] = splits[i][0] - '0';
		(*cnt)++;
		i++;
	}
	return (arr);
}

int	*parse_input(char *input)
{
	char	**splits;
	int		*arr;
	int		cnt;

	if (ft_strlen(input) != 31)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * 16);
	if (!arr)
		return (NULL);
	splits = ft_split(input, " ");
	if (!splits)
		return (free(arr), NULL);
	populate_clues_array(splits, arr, &cnt);
	if (cnt != 16)
		return (free(arr), free_split(splits), NULL);
	free_split(splits);
	return (arr);
}
