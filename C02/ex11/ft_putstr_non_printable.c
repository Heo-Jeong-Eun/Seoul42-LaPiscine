/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:09:24 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/23 13:11:55 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_hex(char ch)
{
	char	*hex;

	hex = "01234566789abcdef";
	if (ch > 16)
	{
		ft_hex(ch / 10);
		ft_hex(ch % 10);
	}
	else
		ft_putchar(hex[ch]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			ft_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i += 1;
	}
}
