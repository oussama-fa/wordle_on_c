#include "wordle.h"

int    pars_input(t_data *data, char *s)
{
    int len = ft_strlen(s);
    if (len < 5 || len > 5)
        return (printf("Please Enter a Word with 5 Carracters\n"), 1);
    int i = 0;
    while (s[i])
    {
        if (!isalpha(s[i]))
            return (printf("Please Enter Just Words !!\n"), 1);
        i++;
    }
    return (0);
}
