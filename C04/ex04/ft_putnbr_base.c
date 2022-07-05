/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 00:09:03 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/30 00:09:20 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base(unsigned int nb, unsigned int size, char *base)
{
	if (nb < size)
		ft_putchar(base[nb]);
	if (nb >= size)
	{
		ft_base(nb / size, size, base);
		ft_base(nb % size, size, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	size;
	int				i;

	i = 0;
	size = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nb = -nbr;
			ft_putchar('-');
		}
		if (nbr >= 0)
			nb = nbr;
		while (base[size] != '\0')
			size++;
		ft_base(nb, size, base);
	}
}
