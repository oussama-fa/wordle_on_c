/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:17:04 by oufarah           #+#    #+#             */
/*   Updated: 2025/07/04 21:18:18 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_H
# define WORDLE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <ctype.h>
# include <time.h>
# include <fcntl.h>
# include "garbage.h"

# define TIME_SLEEP 11111

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

typedef struct s_data
{
	char			**data_base;
	char			*string;
	unsigned int	num;
}t_data;

// gnl utils
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
// ft_split
char	**ft_split(char const *s, char c);
// data base
int		count_data_base(void);
t_data	*read_from_data_base(void);
char	*get_random_word(t_data *data);
// utils
void	ft_putstr_delay(char *s);
void	print_status(char *s1, char *s2);
void	welcome_msg(void);
// parsing
int		pars_input(t_data *data, char *s);

#endif