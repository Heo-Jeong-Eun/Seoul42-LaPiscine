/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:32:47 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/29 21:42:38 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*temp;
	int	i;

	if (min >= max)
		return (0);
	temp = (int *)malloc(sizeof(int) * (max - min));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		temp[i] = min;
		i++;
		min++;
	}
	*range = temp;
	return (i);
}
