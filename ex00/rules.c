/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamani <rolamani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:28:14 by rolamani          #+#    #+#             */
/*   Updated: 2025/09/14 12:48:05 by rolamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	apply_ones(int solve[][4], int index)
{
	if (index >= 0 && index <= 3)
	{
		solve[0][index] = 4;
	}
	else if (index >= 4 && index <= 7)
	{
		solve[3][index - 4] = 4;
	}
	else if (index >= 8 && index <= 11)
	{
		solve[index - 8][0] = 4;
	}
	else if (index >= 12 && index <= 15)
	{
		solve[index - 12][3] = 4;
	}
}

void	apply_one_twos(int solve[][4], int i)
{
	if (i >= 0 && i <= 3)
	{
		solve[i][3] = 3;
	}
	else if (i >= 4 && i <= 7)
	{
		solve[i - 4][0] = 3;
	}
	else if (i >= 8 && i <= 11)
	{
		solve[3][i - 8] = 3;
	}
	else if (i >= 12 && i <= 15)
	{
		solve[0][i - 12] = 3;
	}
}
