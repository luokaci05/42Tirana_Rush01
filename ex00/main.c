/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:25:26 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 12:52:55 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*parse_input(char *input);
int		**solve_game(int *clues);
void	print_solution(int **solve);

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_all(int *clues, int **solution)
{
	int	i;

	if (solution)
	{
		i = 0;
		while (i < 4)
			free(solution[i++]);
		free(solution);
	}
	if (clues)
		free(clues);
}

int	main(int argc, char *argv[])
{
	int	*clues;
	int	**solution;

	if (argc != 2)
		return (print_error(), 1);
	clues = parse_input(argv[1]);
	if (!clues)
		return (free_all(clues, NULL), print_error(), 1);
	solution = solve_game(clues);
	if (!solution)
		return (free_all(clues, NULL), print_error(), 1);
	print_solution(solution);
	free_all(clues, solution);
	return (0);
}
