/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:32:14 by afaqir            #+#    #+#             */
/*   Updated: 2023/09/12 19:37:30 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	_valid_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				printf("Error: %s is not a valid input\n", argv[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	_is_positive(int argc, char **argv)
{
	int	i;

	i = 1;
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Error: %s is not a valid input\n", argv[i]);
		return (1);
	}
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Error: %s is not a valid input\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	_check_input(int argc, char **argv)
{
	if (_valid_numbers(argc, argv))
		return (1);
	if (_is_positive(argc, argv))
		return (1);
	return (0);
}
