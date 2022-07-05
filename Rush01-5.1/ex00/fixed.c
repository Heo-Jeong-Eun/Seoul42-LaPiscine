/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrhee <jrhee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:17:40 by jrhee             #+#    #+#             */
/*   Updated: 2021/09/19 15:26:09 by jrhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		recursive(int board[4][4], int *input);

void	note(int	board[4][4]);

void	check_4_2(int board[4][4], int *input, int loc)
{
	int	num;

	num = 0;
	while ((input[loc]) && loc <= 15)
	{
		if ((input[loc] == 4) && (loc >= 8 && loc <= 11))
		{
			while (num < 4)
			{
				board[loc % 4][num] = num + 1;
				num++;
			}
		}
		num = 4;
		if ((input[loc] == 4) && (loc >= 12 && loc <= 15))
		{
			while (num > 0)
			{
				board[loc % 4][4 - num] = num;
				num--;
			}
		}
		loc++;
	}
}

void	check_4_1(int board[4][4], int *input, int loc)
{
	int	num;

	num = 4;
	while ((input[loc]) && loc < 8)
	{
		if ((input[loc] == 4) && ((loc >= 4 && loc <= 7)))
		{
			while (num > 0)
			{
				board[4 - num][(loc % 4)] = num;
				num--;
			}
		}
		loc++;
	}
	check_4_2(board, input, loc);
}

void	check_4_0(int board[4][4], int *input)
{
	int	loc;
	int	num;

	loc = 0;
	num = 0;
	while ((input[loc]) && loc < 8)
	{
		if ((input[loc] == 4) && ((loc >= 0 && loc <= 3)))
		{
			while (num < 4)
			{
				board[num][loc] = num + 1;
				num++;
			}
		}
		loc++;
	}
	check_4_1(board, input, loc);
}

void	check_1(int	board[4][4], int	*input)
{
	int	loc;

	loc = 0;
	while (input[loc])
	{
		if ((input[loc] == 1) && ((loc >= 0) && (loc <= 3)))
			board[0][loc] = 4;
		if ((input[loc] == 1) && ((loc >= 4) && (loc <= 7)))
			board[3][loc - 4] = 4;
		if ((input[loc] == 1) && ((loc >= 8) && (loc <= 11)))
			board[loc - 8][0] = 4;
		if ((input[loc] == 1) && ((loc >= 12) && (loc <= 15)))
			board[loc - 12][3] = 4;
		loc++;
	}
	check_4_0(board, input);
}

int	writeboard(int	*input)
{
	int	rig;
	int	col;
	int	board[4][4];

	rig = 0;
	col = 0;
	while (rig < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[rig][col] = 0;
			col++;
		}
		rig++;
	}
	check_1(board, input);
	if ((recursive(board, input)) == 1)
		note(board);
	else
		write(1, "Error", 5);
	return (0);
}
