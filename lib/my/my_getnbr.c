/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** convert str in int
*/

static int is_str_neg(char const *str, int *i)
{
    int is_neg = 0;

    while (str[*i] != 0 && (str[*i] == '+' || str[*i] == '-'))
    {
        if (str[*i] == '-' && is_neg == 0)
            is_neg = 1;
        else if (str[*i] == '-' && is_neg == 1)
            is_neg = 0;
        *i = *i + 1;
    }
    return (is_neg);
}

static int is_digit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

static int check_uoflow(int is_neg, int *to_neg, int *ret)
{
    if (*ret > 0 && *to_neg == 1)
    {
        *ret = *ret * -1;
        *to_neg = 0;
    }
    if (*ret != 0 && is_neg == 1 && *ret > 0)
        return (1);
    if (*ret != 0 && is_neg == 0 && *ret < 0)
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int ret = 0;
    int is_neg = is_str_neg(str, &i);
    int to_neg = is_neg;

    while (str[i] != 0 && is_digit(str[i]) == 1)
    {
        if (is_neg == 0 || to_neg == 1)
            ret = (ret * 10) + (str[i] - '0');
        else if (is_neg == 1 && to_neg == 0)
            ret = (ret * 10) - (str[i] - '0');
        if (check_uoflow(is_neg, &to_neg, &ret) == 1)
            return (0);
        i++;
    }
    return (ret);
}
