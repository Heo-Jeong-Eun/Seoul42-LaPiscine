/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:27:16 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/27 22:27:24 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	sqrt;
	unsigned int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (nb);
	sqrt = i * i;
	while (sqrt <= (unsigned int)nb)
	{
		i++;
		sqrt = i * i;
	}
	i -= 1;
	if (i * i != (unsigned int)nb)
		i = 0;
	return (i);
}
