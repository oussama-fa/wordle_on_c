/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:54:23 by oufarah           #+#    #+#             */
/*   Updated: 2025/02/01 21:56:05 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>

# define ALLOC 1
# define CLEAR 2

void	*ft_malloc(size_t size, int flag);

typedef struct s_garbage
{
	void				*address;
	struct s_garbage	*next;

}	t_garbage;

#endif