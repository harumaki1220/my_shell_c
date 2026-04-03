#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[1024];
    char *args[64];
    int i = 0;

    while (1)
    {
        printf("myshell> ");

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("\nBye!\n");
            break;
        }

        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        i = 0;

        char *token = strtok(line, " ");
        while (token != NULL && i < 63)
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        for (int j = 0; j < i; j++)
        {
            printf("args[%d]: %s\n", j, args[j]);
        }
    }

    return 0;
}