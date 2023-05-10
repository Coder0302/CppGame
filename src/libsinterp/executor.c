#include <libsinterp/executor.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsinterp/constructions.h>
#include <libsinterp/variables.h>

void execute(char* text)
{

}
void readFromFile(char* filePath)
{
    FILE* script = fopen(filePath, "r");
    if (script == NULL) {
        printf("Ошибка при открытии файла скрипта.\n");
    }

    char line[256];
    while (fgets(line, sizeof(line), script)) {
        line[strcspn(line, "\n")] = '\0';
        execute(line);
    }

    fclose(script);
}