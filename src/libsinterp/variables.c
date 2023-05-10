#include <stdlib.h>
#include <string.h>

#include <libsinterp/variables.h>

int intValuesCount;
struct IntType* intValues;
void makeInt(char* name, int baseValue)
{
    intValues = realloc(intValues, ++intValuesCount * sizeof(struct IntType));
    struct IntType newInt;
    newInt.baseType.name = name;
    newInt.value = baseValue;
    intValues[intValuesCount-1] = newInt;
}
int getInt(char* name)
{
    for (int i = 0; i < intValuesCount; i++)
    {
        if (strcmp(intValues[i].baseType.name, name) == 0)
        {
            return intValues[i].value;
        }
    }
    return -1;// добавить исключение
}
void setInt(char* name, int newValue)
{
    for (int i = 0; i < intValuesCount; i++)
    {
        if (strcmp(intValues[i].baseType.name, name) == 0)
        {
            intValues[i].value = newValue;
        }
    }
}