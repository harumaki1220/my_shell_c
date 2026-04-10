#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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

        if (i > 0)
        {
            if (strcmp(args[0], "cd") == 0)
            {
                // 組み込みコマンド cd の処理
                if (args[1] == NULL)
                {
                    fprintf(stderr, "cd: 引数が足りません\n");
                }
                else
                {
                    if (chdir(args[1]) != 0)
                    {
                        perror("cd");
                    }
                }
                continue; // forkせずに次のループ（入力待ち）へ戻る
            }
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("fork failed");
            }
            else if (pid == 0)
            {
                if (execvp(args[0], args) == -1)
                {
                    perror("execvp failed");
                    exit(1);
                }

                printf("子プロセス: %s を実行する準備中...\n", args[0]);
                exit(0);
            }
            else
            {
                printf("親プロセス: 子(PID:%d) が終わるのを待っています。\n",
                       pid);
                wait(NULL);
                printf(
                    "親プロセス: 子が終わったので次の入力を受け付けます。\n");
            }
        }
    }

    return 0;
}