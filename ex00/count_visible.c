/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_visible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:55:36 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 12:55:36 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_from_left(int *line)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_from_right(int *line)
{
	int	i;
	int	count;
	int	max;

	i = 3;
	count = 0;
	max = 0;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible(int *line, int direction)
{
	if (direction == 0)
		return (count_visible_from_left(line));
	else
		return (count_visible_from_right(line));
}
