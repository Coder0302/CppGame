#include <libsinterp/executor.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <libsinterp/variables.h>
#include <libsinterp/operators.h>
#include <libsinterp/strlib.h>

// one = 5
// two = one + 4
// print(one)
// print(two)

void cmdWithEqual(char *line)
{
    size_t textLength = 0;
    while (line[textLength++])
        ;
    size_t index = 0;
    char *varName = malloc(textLength * sizeof(char));
    for (size_t i = 0; line[index] != '='; i++)
    {
        varName[i] = line[index++];
    }
    char *operation = charToVar(&(line[++index]));
    char *argumentsResult = arithmeticOperation(operation);
    if (isInteger(argumentsResult))
    {
        int res = atoi(argumentsResult);
        setInt(varName, res);
    }
    else if (isDouble(argumentsResult))
    {
        double res = atof(argumentsResult);
        setDouble(varName, res);
    }
    // executeLine(strstr(line, "=") + 1);
}

void executeLine(char *line)
{
    trimSpaces(&line);

    if (strstr(line, "=") != NULL && strstr(line, "==") == NULL) // Условие для присвоения
    {
        cmdWithEqual(line);
    }
    else if (strstr(line, "read") != NULL)
    {
        char str[10];
        scanf("%s", str);

        char *varName = strstr(line, "read") + 4;
        trimSpaces(&varName);
        if (isInteger(str))
        {
            setInt(varName, atoi(str));
        }
        else if (isDouble(str))
        {
            setDouble(varName, atof(str));
        }
    }
    else if (strstr(line, "print") != NULL)
    {
        char *output = charToVar((char *)(line + 5));
        if (strlen(output) > 0)
        {
            printf("%s\n", output);
        }
        else
        {
            printf("%s\n", line + 5);
        }
    }
}

void execute(char *text)
{
    size_t textLength = 0;
    while (text[textLength++])
        ;

    char *line = malloc(sizeof(char) * 512);
    size_t index = 0;
    size_t lenText = strlen(text);
    while (index < lenText)
    {
        for (size_t i = 0; text[index] != '\n' && text[index] != 0; i++)
        {
            line[i] = text[index];
            line[i + 1] = 0;
            index++;
        }
        index++;
        if (strstr(line, "if") != NULL)
        {
            *strstr(line, "then") = 0;
            char *operation = charToVar(&(line[3]));
            int result = logicalOperation(operation);

            char *newText = malloc(sizeof(char) * 512);
            strcpy(newText, text);
            newText = strstr(newText, "then") + 5;
            char *lastPtrToStr = newText;
            while (strstr(lastPtrToStr, "fi") != NULL)
            {
                lastPtrToStr = strstr(lastPtrToStr, "fi") + 1;
            }
            *(lastPtrToStr - 2) = 0;
            if (result == 1)
            {
                execute(newText);
            }
            index += strlen(newText) + 4;
        }
        if (strstr(line, "while") != NULL)
        {
            *strstr(line, "do") = 0;
            char *operation = charToVar(&(line[6]));
            int result = logicalOperation(operation);

            char *newText = malloc(sizeof(char) * 512);
            strcpy(newText, text);
            newText = strstr(newText, "do") + 3;
            char *lastPtrToStr = newText;
            while (strstr(lastPtrToStr, "done") != NULL)
            {
                lastPtrToStr = strstr(lastPtrToStr, "done") + 1;
            }
            *(lastPtrToStr - 2) = 0;
            while (result == 1)
            {
                operation = charToVar(&(line[6]));
                result = logicalOperation(operation);
                if (result == 1)
                {
                    execute(newText);
                }
            }
            index += strlen(newText) + 6;
        }
        executeLine(line);
    }
    free(line); // Очищаем line
}

char *readFromFile(char *filePath)
{
    FILE *script = fopen(filePath, "r");
    if (script == NULL)
    {
        printf("Ошибка при открытии файла скрипта.\n");
    }
    char *text = malloc(sizeof(char) * 1024);
    fread(text, 1024, 1, script);
    fclose(script);
    return text;
}