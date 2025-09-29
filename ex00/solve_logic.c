/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:34:31 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 13:13:13 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	apply_fours(int solve[][4], int index);
void	apply_ones(int solve[][4], int index);
void	apply_one_twos(int solve[][4], int i);
int		count_visible(int *line, int direction);
int		**alloc_2d_array(int size);
void	init_arr(int arr[4][4]);
void	copy_arr(int **dest, int src[4][4]);
void	free_2d_array(int **arr, int size);

void	apply_rules(int solve[][4], int *clues)
{
	int	i;
	int	pair_idx;

	i = 0;
	while (i < 16)
	{
		if ((i >= 0 && i <= 3) || (i >= 8 && i <= 11))
			pair_idx = i + 4;
		else if ((i >= 4 && i <= 7) || (i >= 12 && i <= 15))
			pair_idx = i - 4;
		if (clues[i] == 4)
			apply_fours(solve, i);
		else if (clues[i] == 1)
		{
			apply_ones(solve, i);
			if (clues[pair_idx] == 2)
				apply_one_twos(solve, i);
		}
		i++;
	}
}

int	check_clues_for_solution(int solve[][4], int *clues)
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		line[0] = solve[0][i];
		line[1] = solve[1][i];
		line[2] = solve[2][i];
		line[3] = solve[3][i];
		if (count_visible(line, 0) != clues[i])
			return (0);
		if (count_visible(line, 1) != clues[i + 4])
			return (0);
		line[0] = solve[i][0];
		line[1] = solve[i][1];
		line[2] = solve[i][2];
		line[3] = solve[i][3];
		if (count_visible(line, 0) != clues[i + 8])
			return (0);
		if (count_visible(line, 1) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	is_safe(int solve[][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (solve[row][i] == num)
			return (0);
		if (solve[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve_backtrack(int solve[][4], int *clues, int row, int col)
{
	int	num;

	if (row == 4)
		return (check_clues_for_solution(solve, clues));
	if (col == 4)
		return (solve_backtrack(solve, clues, row + 1, 0));
	if (solve[row][col] != 0)
		return (solve_backtrack(solve, clues, row, col + 1));
	num = 1;
	while (num <= 4)
	{
		if (is_safe(solve, row, col, num))
		{
			solve[row][col] = num;
			if (solve_backtrack(solve, clues, row, col + 1))
				return (1);
			solve[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	**solve_game(int *clues)
{
	int		**solve;
	int		solve_arr[4][4];

	solve = alloc_2d_array(4);
	if (!solve)
		return (NULL);
	init_arr(solve_arr);
	apply_rules(solve_arr, clues);
	if (!solve_backtrack(solve_arr, clues, 0, 0))
	{
		free_2d_array(solve, 4);
		return (NULL);
	}
	copy_arr(solve, solve_arr);
	return (solve);
}
