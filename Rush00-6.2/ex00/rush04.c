/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:56:43 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/06 10:56:49 by jeonheo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char	ch);

void	rectangle_pos(int col, int row, int max_col, int max_row)
{
	if ((col == 1) && (row == 1))
		ft_putchar('A');
	else if ((col == max_col) && (row == 1))
		ft_putchar('C');
	else if ((col == 1) && (row == max_row))
		ft_putchar('C');
	else if ((col == max_col) && (row == max_row))
		ft_putchar('A');
	else if ((col == 1) || (col == max_col))
		ft_putchar('B');
	else if ((row == 1) || (row == max_row))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			rectangle_pos(col, row, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
