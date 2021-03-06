/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:22:11 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/28 09:22:13 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	lencnt;

	lencnt = 0;
	while (*(str++) != '\0')
	{
		lencnt++;
	}
	return (lencnt);
}
