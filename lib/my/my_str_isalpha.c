/*
** EPITECH PROJECT, 2019
** str_isalpha
** File description:
** checks if str is only alpha
*/

static int is_alpha(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if (is_alpha(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
