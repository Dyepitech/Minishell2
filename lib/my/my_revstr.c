/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverses a char array
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char swap;

    while (str[j] != 0)
        j++;
    j--;
    while (i < j )
    {
        swap = str[i];
        str[i++] = str[j];
        str[j--] = swap;
    }
    return str;
}
