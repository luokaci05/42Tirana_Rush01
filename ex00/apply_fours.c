/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:47:27 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 13:06:53 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill_col_up(int solve[][4], int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solve[i][col] = i + 1;
		i++;
	}
}

void	fill_col_down(int solve[][4], int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solve[i][col] = 4 - i;
		i++;
	}
}

void	fill_row_left(int solve[][4], int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solve[row][i] = i + 1;
		i++;
	}
}

void	fill_row_right(int solve[][4], int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solve[row][i] = 4 - i;
		i++;
	}
}

void	apply_fours(int solve[][4], int index)
{
	if (index >= 0 && index <= 3)
		fill_col_up(solve, index);
	else if (index >= 4 && index <= 7)
		fill_col_down(solve, index - 4);
	else if (index >= 8 && index <= 11)
		fill_row_left(solve, index - 8);
	else if (index >= 12 && index <= 15)
		fill_row_right(solve, index - 12);
}
