/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:53:00 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/25 20:03:12 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char *comb1, char *comb2)
{
	write(1, comb1, 2);
	write(1, " ", 1);
	write(1, comb2, 2);
	if ((comb1[0] != '9' || comb1[1] != '8')
		|| (comb2[0] != '9' || comb2[1] != '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(char *comb1, char *comb2)
{
	while (comb2[0] <= '9')
	{
		while (comb2[1] <= '9')
		{
			ft_putchar(comb1, comb2);
			comb2[1]++;
		}
		comb2[0]++;
		comb2[1] = '0';
	}
	comb1[1]++;
}

void	ft_print_comb2(void)
{
	char	comb1[2];
	char	comb2[2];

	comb1[0] = '0';
	comb1[1] = '0';
	while (comb1[0] <= '9')
	{
		while (comb1[1] <= '9')
		{
			comb2[0] = comb1[0];
			comb2[1] = comb1[1] + 1;
			ft_print_comb(comb1, comb2);
		}
		comb1[0]++;
		comb1[1] = '0';
	}
}
