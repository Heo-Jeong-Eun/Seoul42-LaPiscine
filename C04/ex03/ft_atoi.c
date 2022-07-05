/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:22:36 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/30 00:08:22 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(char *str)
{
	int	m;
	int	result;

	m = 1;
	result = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == ' '
			|| *str == '\v' || *str == '\f' || *str == '\r'))
	{
		++str;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			m *= -1;
		}
		++str;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (result * m);
}
