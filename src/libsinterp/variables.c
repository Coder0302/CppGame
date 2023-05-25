#include <stdlib.h>
#include <string.h>

#include <libsinterp/variables.h>

size_t intValuesCount;
struct IntType *intValues;

size_t doubleValuesCount;
struct DoubleType *doubleValues;

char getType(char *name)
{
    for (size_t i = 0; i < intValuesCount; i++)
    {
        if (intValues[i].baseType.name == name)
        {
            return INT_POINTER;
        }
    }
    for (size_t i = 0; i < doubleValuesCount; i++)
    {
        if (doubleValues[i].baseType.name == name)
        {
            return DOUBLE_POINTER;
        }
    }
    return -1;
}

int haveVar(char *name)
{
    if (getInt(name) == -1 && getDouble(name) == -1)
        return 0;
    else
        return 1;
}

void makeInt(char *name, int baseValue)
{
    intValues = realloc(intValues, ++intValuesCount * sizeof(struct IntType));
    struct IntType newInt;
    newInt.baseType.name = name;
    newInt.value = baseValue;
    intValues[intValuesCount - 1] = newInt;
}
int getInt(char *name)
{
    for (size_t i = 0; i < intValuesCount; i++)
    {
        if (strcmp(intValues[i].baseType.name, name) == 0)
        {
            return intValues[i].value;
        }
    }
    return -1; // добавить исключение
}
void setInt(char *name, int newValue)
{
    if (getInt(name) == -1)
    {
        makeInt(name, newValue);
    }
    for (size_t i = 0; i < intValuesCount; i++)
    {
        if (strcmp(intValues[i].baseType.name, name) == 0)
        {
            intValues[i].value = newValue;
            break;
        }
    }
}

void makeDouble(char *name, double baseValue)
{
    doubleValues = realloc(doubleValues, ++doubleValuesCount * sizeof(struct DoubleType));
    struct DoubleType newDouble;
    newDouble.baseType.name = name;
    newDouble.value = baseValue;
    doubleValues[doubleValuesCount - 1] = newDouble;
}
double getDouble(char *name)
{
    for (size_t i = 0; i < doubleValuesCount; i++)
    {
        if (strcmp(doubleValues[i].baseType.name, name) == 0)
        {
            return doubleValues[i].value;
        }
    }
    return -1; // добавить исключение
}
void setDouble(char *name, double newValue)
{
    if (getDouble(name) == -1)
    {
        makeDouble(name, newValue);
    }
    for (size_t i = 0; i < doubleValuesCount; i++)
    {
        if (strcmp(doubleValues[i].baseType.name, name) == 0)
        {
            doubleValues[i].value = newValue;
        }
    }
}