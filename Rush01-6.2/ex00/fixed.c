/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:27:32 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 17:53:53 by chanwpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int		fill_table(int table[4][4], int *input);
int		check_table(int table[4][4], int *input);
void	print_table(int table[4][4]);

void	fix_line(int table[4][4], int *input)
{
	int	loc;

	loc = 0;
	while (input[loc] != '\0')
	{
		if ((input[loc] == 4) && (loc >= 12 && loc <= 15))
		{
			table[loc - 12][3] = 1;
			table[loc - 12][2] = 2;
			table[loc - 12][1] = 3;
			table[loc - 12][0] = 4;
		}
		else if ((input[loc] == 4) && (loc >= 4 && loc <= 7))
		{
			table[3][loc - 4] = 1;
			table[2][loc - 4] = 2;
			table[1][loc - 4] = 3;
			table[0][loc - 4] = 4;
		}
		loc++;
	}
}

void	fix_max(int	table[4][4], int *input)
{
	int	loc;

	loc = 0;
	while (input[loc])
	{
		if ((input[loc] == 1) && (loc >= 0) && (loc <= 3))
			table[0][loc] = 4;
		else if ((input[loc] == 1) && (loc >= 4) && (loc <= 7))
			table[3][loc - 4] = 4;
		else if ((input[loc] == 1) && (loc >= 8) && (loc <= 11))
			table[loc - 8][0] = 4;
		else if ((input[loc] == 1) && (loc >= 12) && (loc <= 15))
			table[loc - 12][3] = 4;
		loc++;
	}
	fix_line(table, input);
}

int	write_table(int	*input)
{
	int		row;
	int		col;
	int		table[4][4];

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			table[row][col] = 0;
			col++;
		}
		row++;
	}
	fix_max(table, input);
	if (fill_table(table, input) == 1 && check_table(table, input) == 1)
		print_table(table);
	else
		write(1, "Error\n", 6);
	return (0);
}
