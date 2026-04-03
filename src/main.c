#include <stdio.h>
#include <stdlib.h>

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

        printf("You entered: %s", line);
    }

    return 0;
}