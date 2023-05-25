#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <libsinterp/strlib.h>
#include <libsinterp/variables.h>
int logicalOperation(char *text)
{
    trimSpaces(&text);
    size_t textLength = strlen(text);

    char var1[textLength];
    char operator[textLength];
    char var2[textLength];

    char args[3][2] = {">", "<", "=="};

    getArguments(text, 3, args, &var1, &operator, & var2);

    char *endptr1;
    char *endptr2;

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

char *arithmeticOperation(char *text) // (1 + 3) | (2 - 4.5)
{
    trimSpaces(&text);
    if (isInteger(text) || isDouble(text))
    {
        return text;
    }

    size_t textLength = strlen(text);
    char var1[textLength];
    char operator[textLength];
    char var2[textLength];

    getArguments(text, 2, (char **){"+", "-"}, &var1, &operator, & var2);

    char *endptrInt1;
    char *endptrInt2;
    int varInt1 = 0;
    int varInt2 = 0;

    char *endptrDouble1;
    char *endptrDouble2;
    double varDouble1 = 0;
    double varDouble2 = 0;
    // Присваивание инт переменных, если они int
    strtol(var1, &endptrInt1, 10); // проверка на int
    strtol(var2, &endptrInt2, 10); // проверка на int

    // Присваивание double переменных, если они double
    strtod(var1, &endptrDouble1); // проверка на double
    strtod(var2, &endptrDouble2); // проверка на double
    if (*endptrInt1 == '\0')
    {
        varInt1 = atoi(var1);
    }
    if (*endptrInt2 == '\0')
    {
        varInt2 = atoi(var2);
    }
    if (*endptrDouble1 == '\0')
    {
        varDouble1 = atof(var1); // 3.14 | 3
    }
    if (*endptrDouble2 == '\0')
    {
        varDouble2 = atof(var2);
    }

    if (*endptrInt1 == '\0' && *endptrInt2 == '\0')
    {
        if (strcmp(operator, "+") == 0)
        {
            char *var = malloc(sizeof(char) * 10);
            sprintf(var, "%d", varInt1 + varInt2);
            return var;
        }
        else if (strcmp(operator, "-") == 0)
        {
            char *var = malloc(sizeof(char) * 10);
            sprintf(var, "%d", varInt1 - varInt2);
            return var;
        }
    }
    else if (*endptrDouble1 == '\0' || *endptrDouble2 == '\0')
    {
        if (strcmp(operator, "+") == 0)
        {
            char *var = malloc(sizeof(char) * 10);
            double res = varDouble1 + varDouble2;
            sprintf(var, "%f", res);
            return var;
        }
        else if (strcmp(operator, "-") == 0)
        {
            char *var = malloc(sizeof(char) * 10);
            double res = varDouble1 - varDouble2;
            sprintf(var, "%f", res);
            return var;
        }
    }
    return NULL;
}