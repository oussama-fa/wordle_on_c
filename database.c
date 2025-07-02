#include "wordle.h"

int count_data_base()
{
    int fd = open ("database.txt", O_RDONLY);
    if (fd == -1)
        return (fprintf(stderr, "Can't Open File DATA BASE\n"), 1);
    char *line = get_next_line(fd);
    int count = 0;
    while (line)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        count++;
        free(line);
    }
    return (count);
}

t_data    *read_from_data_base()
{
    char    *line = ft_strdup("");
    int fd = open ("database.txt", O_RDONLY);
    if (fd == -1)
        return (fprintf(stderr, "Can't Open File DATA BASE\n"), NULL);
    int count = count_data_base();
    t_data *data = ft_malloc(sizeof(char **) * count, ALLOC);
    if (!data)
        return (close(fd), NULL);
    char    *string = ft_strdup("");
    line = get_next_line(fd);
    string = ft_strjoin(string, line);
    if (!line)
        return (close(fd), NULL);
    while (line)
    {
        line = get_next_line(fd);
        string = ft_strjoin(line, string);
        free(line);
        if (!line)
            break ;
    }
    data->data_base = ft_split(string, '\n');
    data->num = count;
    return (data);
}

char    *get_random_word(t_data *data)
{
    char *ret = NULL;
    int i = -1;
    int random_index = 0;
    srand(time(NULL));
    random_index = rand() % data->num;    
    ret = ft_strdup(data->data_base[random_index]);
    return (ret);
}
