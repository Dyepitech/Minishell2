/*
** EPITECH PROJECT, 2019
** str_isprintable
** File description:
** checks if str is only printable
*/

static int is_printable(char c)
{
    if (' ' <= c && c <= '~')
        return (1);
    return (0);
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_printable(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
