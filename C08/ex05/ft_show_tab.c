/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:01:11 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/30 00:20:33 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_show_tab(struct s_stock_str *tab)
{
	int	i;

	i = 0;
	while (tab[i].str != 0)
	{
		ft_putstr(tab[i].str);
		ft_putstr("\n");
		ft_putnbr(tab[i].size);
		ft_putstr("\n");
		ft_putstr(tab[i].copy);
		ft_putstr("\n");
		i++;
	}
}
