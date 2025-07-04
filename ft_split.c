/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:03:39 by oufarah           #+#    #+#             */
/*   Updated: 2025/07/04 21:35:50 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wordle.h"

static size_t	cnt_w(char *str, char c)
{
	size_t	i;
	size_t	rst;
	size_t	cnt;

	i = 0;
	rst = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			rst = 0;
		else if (rst == 0)
		{
			rst = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	s = ft_malloc(n + 1, ALLOC);
	while (n--)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	ft_split_helper(int *i, char const *s, char c)
{
	int	start;

	while (s[*i] == c && (s[*i]))
		(*i)++;
	start = *i;
	while (s[*i] != c && (s[*i]))
		(*i)++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	int		start;
	char	**strs;

	if (!s)
		return (NULL);
	(1) && (i = 0, word = 0, start = 0);
	strs = ft_malloc((sizeof(char *)) * (cnt_w((char *)s, c) + 1), ALLOC);
	if (!strs)
		return (NULL);
	while (s[i])
	{
		start = ft_split_helper(&i, s, c);
		if (i > start)
			strs[word++] = ft_strndup((char *)s + start, i - start);
	}
	strs[word] = NULL;
	return (strs);
}
