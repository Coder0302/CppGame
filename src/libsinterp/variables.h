struct BaseType
{
    char* name;
};

struct DoubleType
{
    struct BaseType baseType;
    double value;
    double(*GetInt)(char*);
    void(*SetInt)(char*, double);
};
void makeDouble(char* name, double baseValue);
double getDouble(char* name);
void setDouble(char* name, double newValue);

struct IntType
{
    struct BaseType baseType;
    int value;
    int(*GetInt)(char*);
    void(*SetInt)(char*, int);
};
int getInt(char* name);
void setInt(char* name, int newValue);