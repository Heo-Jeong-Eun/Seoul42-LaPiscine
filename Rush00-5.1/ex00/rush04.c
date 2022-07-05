/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungbki <seungbki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:43:22 by seungbki          #+#    #+#             */
/*   Updated: 2021/09/12 09:52:08 by seungbki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ASCII_TOP_LEFT 65
#define ASCII_TOP_RIGHT 67
#define ASCII_BOTTOM_LEFT 67
#define ASCII_BOTTOM_RIGHT 65
#define ASCII_VERTICAL_EDGE 66
#define ASCII_HORIZONTAL_EDGE 66
#define ASCII_FILL 32

/*
 * 	**** ASCII CODE ****
 *
 * 	A	:	65
 * 	B	:	66
 * 	C	:	67
 * 	 	:	32
 *
 * 	자세한 정보는 man ascii 참고
 */

void	ft_putchar(char c);

char	g_rectangle[7];

void	init_rectangle(void)
{
	g_rectangle[0] = ASCII_TOP_LEFT;
	g_rectangle[1] = ASCII_TOP_RIGHT;
	g_rectangle[2] = ASCII_BOTTOM_LEFT;
	g_rectangle[3] = ASCII_BOTTOM_RIGHT;
	g_rectangle[4] = ASCII_VERTICAL_EDGE;
	g_rectangle[5] = ASCII_HORIZONTAL_EDGE;
	g_rectangle[6] = ASCII_FILL;
}

int	get_rectangle_idx(int cur_col, int cur_row, int max_col, int max_row)
{
	if ((cur_col == 1) && (cur_row == 1))
	{
		return (0);
	}
	if ((cur_col == max_col) && (cur_row == 1))
	{
		return (1);
	}
	if ((cur_col == 1) && (cur_row == max_row))
	{
		return (2);
	}
	if ((cur_col == max_col) && (cur_row == max_row))
	{
		return (3);
	}
	if ((cur_col == 1) || (cur_col == max_col))
	{
		return (4);
	}
	if ((cur_row == 1) || (cur_row == max_row))
	{
		return (5);
	}
	return (6);
}

void	draw_rectangle(int cur_col, int cur_row, int max_col, int max_row)
{
	int	rectangle_idx;

	rectangle_idx = get_rectangle_idx(cur_col, cur_row, max_col, max_row);
	ft_putchar(g_rectangle[rectangle_idx]);
}

void	rush(int x, int y)
{
	int	cur_row;
	int	cur_col;

	init_rectangle();
	cur_row = 1;
	while (cur_row <= y)
	{
		cur_col = 1;
		while (cur_col <= x)
		{
			draw_rectangle(cur_col, cur_row, x, y);
			cur_col++;
		}
		ft_putchar('\n');
		cur_row++;
	}
}
