/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:11:48 by oufarah           #+#    #+#             */
/*   Updated: 2025/07/04 21:15:02 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

void	ft_putstr_delay(char *s)
{
	while (*s)
	{
		write(1, s++, 1);
		usleep(TIME_SLEEP);
	}
}

void	print_status(char *s1, char *s2)
{
	char	*lower_word;
	int		len;
	int		i;

	len = ft_strlen(s2);
	lower_word = ft_malloc(len + 1, ALLOC);
	i = -1;
	while (s2[++i])
		lower_word[i] = tolower(s2[i]);
	lower_word[i] = '\0';
	printf("\n");
	if (!strcmp(s1, lower_word))
	{
		printf("\033[33m[ YOU WIN ]\033[0m\n");
		exit(0);
	}
	i = -1;
	while (++i < 5)
	{
		if (s1[i] == lower_word[i])
			printf("\033[32m[%c]\033[0m", s1[i]);
		else
			printf("\033[31m[%c]\033[0m", lower_word[i]);
	}
	printf("\n");
}

void	welcome_msg(void)
{
	char	*msg;
	char	*msg_3;
	char	*msg_4;
	char	*msg_5;

	msg = "Hello !\n";
	msg_3 = "Can you Guess The Word ?!\n";
	msg_4 = "Get 6 Chances to Guess\n";
	msg_5 = "<<< a 5-letter Word >>>\n";
	ft_putstr_delay(msg);
	usleep(TIME_SLEEP);
	ft_putstr_delay(msg_3);
	usleep(TIME_SLEEP);
	ft_putstr_delay(msg_4);
	usleep(TIME_SLEEP);
	ft_putstr_delay(msg_5);
	usleep(TIME_SLEEP);
}
