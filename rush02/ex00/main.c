/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:30:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/05/01 21:07:32 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	main(int argc, char **argv)
{
	t_number	*number;
	t_digits	*digit;
	char		*dict;
	char		*input;

	init_all(&input, &dict, &number, &digit);
	if (!check_dict(argc, argv, &input, &dict))
		ft_puterr("Error\n");
	else if (!check_input_part1(&input, 0))
		ft_puterr("Error\n");
	else
	{
		if (ft_read(dict, &number, &digit) == 1)
		{
			ft_num_sort(&number);
			ft_digit_sort(&digit);
			if (!(digit->key + 3 <= ft_strlen(input)))
				sep_num(input, number, digit, ft_strlen(input));
			else
				ft_puterr("Dict Error\n");
		}
		else
			ft_puterr("Dict Error\n");
	}
	return (0);
}
