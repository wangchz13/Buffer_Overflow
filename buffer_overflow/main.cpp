#include <stdio.h>
#include <string.h>

char name[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    char output[8];
    strcpy(output, name);
    for (int i = 0; i < 8&&output[i]; i++)
    {
        printf("\\0x%x", output[i]);
    }
    return 0;
}