#include <libsinterp/commands.h>
#include <vector.h>

struct Var
{
    char* name;
    int typeVar;// 0 - int, 1 - double
};

void makeVariable(char* name, int baseValue)
{
    
//i = 0
//execute("i = 0")
//i = int -> setInt("i", 0)
//makeVar("i", 0)
//vars.Add(Var("i", typeof(int)))
}
struct VarInt getVariable(char* name)
{
    struct VarInt integer = ;
    integer.value = 0;
    return integer;
}
void setVariable(char* name, int newValue)
{

}