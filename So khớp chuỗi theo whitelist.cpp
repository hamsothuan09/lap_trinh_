#include <stdio.h>
#include <string.h>

int main() {
    char cmd[50];
    char *safe[] = {"ls", "pwd", "whoami"};
    int ok = 0;

    scanf("%s", cmd);

    for (int i = 0; i < 3; i++) {
        if (strcmp(cmd, safe[i]) == 0) {
            ok = 1;
            break;
        }
    }

    if (ok)
        printf("Lenh hop le\n");
    else
        printf("Lenh bi chan\n");

    return 0;
}