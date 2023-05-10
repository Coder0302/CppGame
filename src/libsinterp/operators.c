#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void trimSpaces(char** text)
{
    int textLength = 0;
    while((*text)[textLength++]){}

    char clearText[textLength];

    int i = 0;
    int index = 0;
    while ((*text)[i])
    {
        if (!isspace((*text)[i]))
        {
            clearText[index++] = (*text)[i];
        }
        i++;
    }
    *text = clearText;
}

int logicalOperation(char* text)
{
    trimSpaces(&text);
    int textLength = 0;
    while(text[textLength++]){}
    
    char var1[textLength];
    char operator[textLength];
    char var2[textLength];

    int i = 0;
    for (int index = 0; isdigit(text[i]) || text[i] == '.'; index++)
    {
        var1[index] = text[i++];
        var1[index+1] = '\0';
    }
    for (int index = 0; text[i] == '<' || text[i] == '>' || text[i] == '='; index++)
    {
        operator[index] = text[i++];
        operator[index+1] = '\0';
    }
    for (int index = 0; isdigit(text[i]) || text[i] == '.'; index++)
    {
        var2[index] = text[i++];
        var2[index+1] = '\0';
    }

    char* endptr1;
    char* endptr2;

    if (strcmp(operator, ">") == 0)
    {
        strtol(var1, &endptr1, 10);
        strtol(var2, &endptr2, 10);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atoi(var1) > atoi(var2);
        }

        strtod(var1, &endptr1);
        strtod(var2, &endptr2);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atof(var1) > atof(var2);
        }
    }
    else if (strcmp(operator, "<") == 0)
    {
        strtol(var1, &endptr1, 10);
        strtol(var2, &endptr2, 10);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atoi(var1) < atoi(var2);
        }

        strtod(var1, &endptr1);
        strtod(var2, &endptr2);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atof(var1) < atof(var2);
        }
    }
    else if (strcmp(operator, "==") == 0)
    {
        strtol(var1, &endptr1, 10);
        strtol(var2, &endptr2, 10);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atoi(var1) == atoi(var2);
        }

        strtod(var1, &endptr1);
        strtod(var2, &endptr2);
        if (*endptr1 == '\0' && *endptr2 == '\0')
        {
            return atof(var1) == atof(var2);
        }
    }
    return -1;
}

int arithmeticOperation(char* text)
{
    return -1;
}