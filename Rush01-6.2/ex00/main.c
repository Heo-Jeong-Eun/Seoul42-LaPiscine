/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonheo <jeonheo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:28:29 by jeonheo           #+#    #+#             */
/*   Updated: 2022/02/13 15:28:12 by chanwpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	write_table(int *input);

int	check_input(char *argv, int *input)
{
	int	i;

	i = 0;
	while (argv[i])
	{	
		if (argv[i] >= '1' && argv[i] <= '4' && (i % 2 == 0))
		{
			*input = (argv[i] - '0');
			i++;
			input++;
		}
		else if (argv[i] == ' ' && (i % 2) == 1)
			i++;
		else
			return (0);
	}
	*input = '\0';
	return (i);
}

int	main(int argc, char **argv)
{
	int	input[16];

	if (argc == 2)
	{
		if (check_input(argv[1], input) == 31)
			write_table(input);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
