#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "dictionary.h"

#define maxn 1000

FILE *input, *output;

void MakeText()
{
    return;
}

int main()
{
    srand(time(0));
    input = fopen("tests.txt", "r");
    output = fopen("result.txt", "w");
    char s[maxn];
    int flag = 0;
    while (fgets(s, maxn, input) != 0)
    {
        if (!flag)
        {
            flag = 1;
            continue;
        }
        else MakeText();
    }

    return 0;
}
