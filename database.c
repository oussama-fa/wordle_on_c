/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:02:40 by oufarah           #+#    #+#             */
/*   Updated: 2025/07/04 21:39:48 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

int	count_data_base(void)
{
	int		fd;
	int		count;
	char	*line;

	fd = open("database.txt", O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Can't Open File DATA BASE\n"), 1);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
	}
	return (count);
}

t_data	*read_from_data_base(void)
{
	char	*line;
	char	*string;
	int		fd;
	int		count;
	t_data	*data;

	fd = open("database.txt", O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Can't Open File DATA BASE\n"), NULL);
	count = count_data_base();
	data = ft_malloc(sizeof(char **) * count, ALLOC);
	line = get_next_line(fd);
	string = ft_strjoin(string, line);
	if (!line)
		return (close(fd), NULL);
	while (line)
	{
		line = get_next_line(fd);
		string = ft_strjoin(line, string);
		if (!line)
			break ;
	}
	data->data_base = ft_split(string, '\n');
	data->num = count;
	return (data);
}

char	*get_random_word(t_data *data)
{
	char	*ret;
	int		i;
	int		random_index;

	ret = NULL;
	i = -1;
	random_index = 0;
	srand(time(NULL));
	random_index = rand() % data->num;
	ret = ft_strdup(data->data_base[random_index]);
	return (ret);
}
