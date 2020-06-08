/*
** EPITECH PROJECT, 2019
** strcapitalize
** File description:
** capitalize all words !!!!
*/

static int is_alphanum(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return (1);
    else if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != 0)
    {
        if ('A' <= str[i] && str[i] <= 'Z' &&
            i > 0 && is_alphanum(str[i - 1]) == 1)
                str[i] = str[i] - 'A' + 'a';
        else if ('a' <= str[i] && str[i] <= 'z' &&
                (i == 0 || is_alphanum(str[i - 1]) == 0))
            str[i] = str[i] - 'a' + 'A';
        i++;
    }
    return (str);
}
