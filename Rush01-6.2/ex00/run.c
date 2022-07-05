/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:30:36 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 17:54:22 by chanwpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_table(int table[4][4], int *input);

int	check_zero(int table[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (table[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int	is_same_column(int table[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (table[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	is_same_row(int table[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (table[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	check_safe(int table[4][4], int row, int col, int num)
{
	if (((is_same_row(table, row, num))
			&& (is_same_column(table, col, num))
			&& (table[row][col] == 0)))
	{
		return (1);
	}
	return (0);
}

int	fill_table(int table[4][4], int *input)
{
	int	row;
	int	col;
	int	n;

	n = 1;
	if ((check_zero(table, &row, &col) == 0)
		&& (check_table(table, input) == 1))
		return (1);
	while (n <= 4)
	{
		if (check_safe(table, row, col, n) == 1)
		{
			table[row][col] = n;
			if ((fill_table(table, input) == 1))
				return (1);
			table[row][col] = 0;
		}
		n++;
	}
	return (0);
}
