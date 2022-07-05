/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:22:21 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/28 09:22:23 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		write (1, &str[cnt], 1);
		cnt++;
	}
}