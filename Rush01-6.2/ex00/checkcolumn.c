/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcolumn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:23:41 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 11:23:44 by jeonheo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int table[4][4], int col, int num)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	count = 1;
	max = table[i][col];
	while (i < 4)
	{
		if (table[i][col] > max)
		{
			max = table[i][col];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_coldown(int table[4][4], int col, int num)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = table[i][col];
	while (i >= 0)
	{
		if (table[i][col] > max)
		{
			max = table[i][col];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}
