/*
** EPITECH PROJECT, 2019
** str_isnum
** File description:
** checks if str is only digits
*/

static int is_digit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_digit(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
