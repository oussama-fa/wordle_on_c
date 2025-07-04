/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:10:46 by oufarah           #+#    #+#             */
/*   Updated: 2025/07/04 21:29:01 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	main(void)
{
	t_data	*data;
	char	*random_word;
	char	input_str[6];
	int		i;

	welcome_msg();
	data = read_from_data_base();
	random_word = get_random_word(data);
	ft_putstr_delay("Enter the World you Guess : \n");
	scanf("%s", &input_str);
	if (pars_input(data, input_str))
		return (ft_malloc(0, CLEAR), 1);
	i = -1;
	while (++i < 6)
	{
		print_status(random_word, input_str);
		scanf("%s", &input_str);
		if (pars_input(data, input_str))
			return (ft_malloc(0, CLEAR), 1);
	}
	printf("\033[35m[ YOU LOSE ]\033[0m\n");
	printf("The Word is : [%s]\n", random_word);
	ft_malloc(0, CLEAR);
	return (1);
}
