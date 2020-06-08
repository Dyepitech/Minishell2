/*
** EPITECH PROJECT, 2019
** str_islower
** File description:
** checks if str is only lower alpha
*/

static int is_lowalpha(char c)
{
    if (('a' <= c && c <= 'z'))
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_lowalpha(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
