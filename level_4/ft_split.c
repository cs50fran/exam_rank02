/*

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

*/

#include <stdio.h>
#include <stdlib.h>

int is_space(char c)
{
    return(c == 32 || ( c >= 9 && c <= 13));
}

size_t count_words(char *s)
{
    size_t count = 0;
    int i = 0;

    while(s[i])
    {
        while(is_space(s[i]))
            i++;
        if(s[i] && !is_space(s[i]))
            count++;
        while(s[i] && !is_space(s[i]))
            i++;
    }
    return count;
}

char *ft_substr(char *str, int start, int len)
{
    int i = 0;
    char *goal = malloc(sizeof(char) * (len + 1));
    if(!goal)
        return NULL;
    while(str[start + i] && i < len)
    {
        goal[i] = str[start + i];
        i++;
    }
    goal[i] = '\0';
    return goal;
}

char **get_words(char *str, int words)
{
    char ** words_array = malloc(sizeof(char *) * (words + 1));
    if(!words_array)
        return NULL;
    int i = 0;
    int j;
    int k = 0;
    while(k < words && str[i])
    {
        j = 0;
        while (str[i] && is_space(str[i]))
            i++;
        while (str[i + j] && !is_space(str[i + j]))
            j++;
        words_array[k] = ft_substr(str, i, j);
        if (!words_array[k])
        {
            while (k > 0)
                free(words_array[--k]);
            free(words_array);
            return NULL;
        }
        k++;
        i += j;
    }
    words_array[k] = NULL;
    return words_array;
}

void free_split(char **split)
{
    if (!split)
        return;
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

char    **ft_split(char *str)
{
    if(!str)
        return NULL;
    int words = count_words(str);
    char **goal = get_words(str, words);
    return goal;
}


int main(void)
{
    char *test1 = "Hello   world\tfrom\nC";
    char *test2 = "   ";
    char *test3 = "single";
    
    printf("Test 1: \"%s\"\n", test1);
    char **arr1 = ft_split(test1);
    for (int i = 0; arr1[i]; i++)
        printf("  [%d]: \"%s\"\n", i, arr1[i]);
    free_split(arr1);
    
    printf("\nTest 2 (only spaces): \"%s\"\n", test2);
    char **arr2 = ft_split(test2);
    if (arr2[0] == NULL)
        printf("  (empty result)\n");
    free_split(arr2);
    
    printf("\nTest 3: \"%s\"\n", test3);
    char **arr3 = ft_split(test3);
    for (int i = 0; arr3[i]; i++)
        printf("  [%d]: \"%s\"\n", i, arr3[i]);
    free_split(arr3);
    
    return 0;
}


