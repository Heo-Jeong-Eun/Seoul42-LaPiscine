/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrhee <jrhee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:07:52 by jrhee             #+#    #+#             */
/*   Updated: 2021/09/19 12:47:23 by jrhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	checkboard(int board[4][4], int *num_in);

int	check_0(int board[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == 0)
			{
				return (1);
			}
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int	samecol(int board[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == num)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	samerow(int board[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == num)
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	checksafe(int board[4][4], int row, int col, int num)
{
	if (((samerow(board, row, num)) && (samecol(board, col, num))
			&& (board[row][col] == 0)))
	{
		return (1);
	}
	return (0);
}

int	recursive(int board[4][4], int *input)
{
	int	row;
	int	col;
	int	n;

	n = 1;
	if ((check_0 (board, &row, &col) == 0) && (checkboard (board, input) == 1))
	{
		return (1);
	}
	while (n <= 4)
	{
		if (checksafe(board, row, col, n))
		{
			board [row][col] = n;
			if (recursive(board, input) == 1)
			{
				return (1);
			}
			board[row][col] = 0;
		}
		n++;
	}
	return (0);
}
