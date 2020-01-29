#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNext(char *pat, int *next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < strlen(pat)) {
        if (j == -1 || pat[i] == pat[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int kmpSearch(char *str, char *pat)
{
    int i = 0, j = 0;
    int retval = -1;
    int *next;
    int slen = strlen(str);
    int plen = strlen(pat);

    next = (int*)malloc(sizeof(int) * (plen + 1));
    getNext(pat, next);
    while (i < slen && j < plen) {
        if (j == -1 || str[i] == pat[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == plen) {
        retval = i - j;
    }
    free(next);
    return retval;
}

int main(void)
{
    char *str = "jihongzhiaaabcdabdaaaaa";
    char *pat = "zhi";
    int pos;

    pos = kmpSearch(str, pat);
    printf("%d\n", pos);

    return 0;
}

