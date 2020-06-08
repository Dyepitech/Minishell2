/*
** EPITECH PROJECT, 2019
** str_isupper
** File description:
** checks if str is only up alpha
*/

static int is_upalpha(char c)
{
    if ('A' <= c && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_upalpha(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
