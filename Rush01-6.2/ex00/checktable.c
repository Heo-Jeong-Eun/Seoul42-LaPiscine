/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:21:49 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 17:53:42 by chanwpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int table[4][4], int col, int num);
int	check_coldown(int table[4][4], int col, int num);
int	check_rowleft(int table[4][4], int row, int num);
int	check_rowright(int table[4][4], int row, int num);

int	check_left_right(int table[4][4], int *input)
{
	int	i;

	i = 8;
	while (input[i] != '\0')
	{
		if (i >= 8 && i <= 11)
		{
			if (check_rowleft(table, i - 8, input[i]) != 1)
				return (0);
		}
		else if (i >= 12 && i <= 15)
		{
			if (check_rowright(table, i - 12, input[i]) != 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_up_down(int table[4][4], int *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (i >= 0 && i <= 3)
		{
			if (check_colup(table, i, input[i]) != 1)
				return (0);
		}
		else if (i >= 4 && i <= 7)
		{
			if (check_coldown(table, i - 4, input[i]) != 1)
				return (0);
		}
		i++;
	}
	if (check_left_right(table, input) != 1)
		return (0);
	return (1);
}

int	check_table(int table[4][4], int *input)
{
	return (check_up_down(table, input));
}
