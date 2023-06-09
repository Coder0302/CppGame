char getType(char *name);
int haveVar(char *name);

struct BaseType
{
    char *name;
};

#define DOUBLE_POINTER 'd'
struct DoubleType
{
    struct BaseType baseType;
    double value;
};
struct DoubleType *doubleValues;
void makeDouble(char *name, double baseValue);
double getDouble(char *name);
void setDouble(char *name, double newValue);

#define INT_POINTER 'i'
struct IntType
{
    struct BaseType baseType;
    int value;
};
void makeInt(char *name, int baseValue);
int getInt(char *name);
void setInt(char *name, int newValue);