/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrhee <jrhee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:26:06 by jrhee             #+#    #+#             */
/*   Updated: 2021/09/20 16:33:20 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int board[4][4], int col, int num);
int	check_coldown(int board[4][4], int col, int num);
int	check_rowleft(int board[4][4], int row, int num);
int	check_rowright(int board[4][4], int row, int num);

int	checkboard2(int board[4][4], int *num_in, int i)
{
	while (num_in[i])
	{
		if (i >= 8 && i <= 11)
		{
			if (!check_rowleft(board, i - 8, num_in[i]))
				return (0);
		}
		if (i >= 12 && i <= 15)
		{
			if (!check_rowright(board, i - 12, num_in[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkboard(int board[4][4], int *num_in)
{
	int	i;

	i = 0;
	while (num_in[i])
	{
		if (i >= 0 && i <= 3)
		{
			if (!check_colup(board, i, num_in[i]))
				return (0);
		}
		if (i >= 4 && i <= 7)
		{
			if (!check_coldown(board, i - 4, num_in[i]))
				return (0);
		}
		i++;
	}
	checkboard2(board, num_in, i);
	return (1);
}
