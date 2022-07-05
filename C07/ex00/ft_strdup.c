/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeoheo <jeoheo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:32:27 by jeoheo            #+#    #+#             */
/*   Updated: 2021/09/29 21:35:20 by jeoheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*srcdup;

	len = 0;
	while (src[len])
		len++;
	srcdup = (char *)malloc(sizeof(char) * len + 1);
	if (srcdup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		srcdup[i] = src[i];
		i++;
	}
	srcdup[i] = '\0';
	return (srcdup);
}
