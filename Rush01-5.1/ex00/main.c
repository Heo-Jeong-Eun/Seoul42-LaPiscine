/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrhee <jrhee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:57:14 by jrhee             #+#    #+#             */
/*   Updated: 2021/09/19 15:28:53 by jrhee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	writeboard(int *input);

int	checkvalue(char	*input)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (input[i])
	{
		if (input[i] == '4')
			err++;
		i++;
	}
	if (err > 2)
		return (0);
	i = 0;
	err = 0;
	while (input[i])
	{
		if (input[i] == '1')
			err++;
		i++;
	}
	if (err != 4)
		return (0);
	return (1);
}

int	checkinput(char *arr, int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (checkvalue(arr) == 1)
	{
		while (arr[i])
		{	
			if ((arr[i] >= '1' && arr[i] <= '4') && ((arr[i + 1] == ' ')
					|| ((arr[i + 1] == 0) && (arr[i - 1] == ' '))))
			{
				input[j] = (arr[i] - '0');
				j++;
				i++;
			}
			if ((arr[i] >= 9 && arr[i] <= 13) || arr[i] == 32)
				i++;
			else
				return (j);
		}
		input[j] = '\0';
		return (j);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	input[16];

	if (argc == 2)
	{
		if (checkinput(argv[1], input) == 16)
			writeboard(input);
		else
			write(1, "Error", 5);
	}
	else
	{
		write(1, "Error", 5);
	}
	return (0);
}
