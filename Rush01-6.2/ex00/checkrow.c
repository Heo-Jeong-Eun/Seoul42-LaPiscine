/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:24:52 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 11:24:54 by jeonheo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rowleft(int table[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	count = 1;
	max = table[row][i];
	while (i < 4)
	{
		if (table[row][i] > max)
		{
			max = table[row][i];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_rowright(int table[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = table[row][i];
	while (i >= 0)
	{
		if (table[row][i] > max)
		{
			max = table[row][i];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}
