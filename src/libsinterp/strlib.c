#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <libsinterp/variables.h>

void trimSpaces(char **text)
{
    size_t i = 0;
    size_t index = 0;
    size_t textLength = strlen(*text);
    char *clearText = malloc(textLength * sizeof(char));

    while ((*text)[i])
    {
        if (!isspace((*text)[i]))
        {
            clearText[index] = (*text)[i];
            clearText[++index] = 0;
        }
        i++;
    }
    *text = clearText;
}

char *charToVar(char *line)
{
    // afhgf + bfgh
    // aasd
    // 5 + asff
    size_t indexLine = 0;
    size_t indexResult = 0;
    char *result = malloc(sizeof(char) * 512);
    while (indexLine < strlen(line))
    {
        char varName[32] = "";
        for (size_t i = 0; isalpha(line[indexLine]); i++)
        {
            varName[i] = line[indexLine];
            varName[i + 1] = 0;
            indexLine++;
        }
        if (strcmp(varName, "") != 0)
        {
            if (getInt(varName) != -1)
            {
                char var[17];
                sprintf(var, "%d", getInt(varName));
                strcat(result, var);
                indexResult += strlen(var);
                indexLine--;
            }
            else if (getDouble(varName) != -1)
            {
                char var[17];
                sprintf(var, "%f", getDouble(varName));
                strcat(result, var);
                indexResult += strlen(var);
                indexLine--;
            }
        }
        else
        {
            result[indexResult++] = line[indexLine];
        }
        indexLine++;
    }
    return result;
}

int isInteger(char *text)
{
    char *endptr1;
    strtol(text, &endptr1, 10);
    return *endptr1 == '\0';
}
int isDouble(char *text)
{
    char *endptr1;
    strtod(text, &endptr1);
    return *endptr1 == '\0';
}

void getArguments(char *text, int countSeparators, char separators[countSeparators][2], char (*v1)[], char (*op)[], char (*v2)[])
{
    size_t textLength = strlen(text);
    size_t i = 0;
    char var1[textLength];
    char operator[textLength];
    char var2[textLength];

    for (size_t index = 0; isdigit(text[i]) || text[i] == '.'; index++)
    {
        var1[index] = text[i++];
        var1[index + 1] = '\0';
    }
    for (size_t j = 0; j < countSeparators; j++)
    {
        char *sep = separators[j];
        if (strstr(text, sep) != NULL && strlen(sep) > 0)
        {
            strcpy(operator, sep);
            size_t len = strlen(sep);
            i += len;
            break;
        }
    }
    for (size_t index = 0; isdigit(text[i]) || text[i] == '.'; index++)
    {
        var2[index] = text[i++];
        var2[index + 1] = '\0';
    }
    strcpy(*v1, var1);
    strcpy(*op, operator);
    strcpy(*v2, var2);
}