#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[1024];

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

        printf("You entered: %s", line);
    }

    return 0;
}