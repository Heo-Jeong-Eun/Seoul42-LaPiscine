/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:31:55 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/21 18:38:11 by jeoheo           ###   ########.fr       */
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
