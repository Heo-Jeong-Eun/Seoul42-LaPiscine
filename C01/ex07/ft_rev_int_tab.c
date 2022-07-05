/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:41:52 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/21 18:43:33 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < (size / 2))
	{
		temp = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = temp;
		index++;
	}
}
