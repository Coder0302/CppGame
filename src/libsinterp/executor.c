#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsinterp/executor.h>
#include <libsinterp/commands.h>

void execute(char* text)
{

}
char* readFromFile(char* filePath)
{
    FILE* script = fopen(filePath, "r");
    if (script == NULL) {
        printf("Ошибка при открытии файла скрипта.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), script)) {
        line[strcspn(line, "\n")] = '\0';
        executeCommand(line);
    }

    fclose(script);
}