#ifndef WORDEL_H
#define WORDEL_H

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
# define BUFFER_SIZE 6
# endif

typedef struct s_data
{
    char    **data_base;
    char    *string;
    unsigned int num;
}   t_data;


// gnl utils
char    *ft_strchr(char *s, char c);
size_t  ft_strlen(const char *s);
char    *ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char    *ft_strchr(char *s, char c);
char    *ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(const char *s);
// ft_split
char    **ft_split(char const *s, char c);
// data base
int count_data_base(void);
t_data    *read_from_data_base(void);
char    *get_random_word(t_data *data);
// utils
void    ft_putstr_delay(char *s);
void    print_status(char *s1, char *s2);
void    Welcome_msg(void);
// parsing
int    pars_input(t_data *data, char *s);
#endif