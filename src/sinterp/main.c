#include <libsinterp/variables.h>
#include <libsinterp/executor.h>
#include <libsinterp/operators.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    makeInt("is", 0);
    makeInt("two", 2);
    printf("%d\n", getInt("is"));
    setInt("is", 1);
    printf("%d\n", getInt("is"));
    setInt("is", getInt("is") + getInt("two"));

    printf("%d\n", getInt("is"));
    printf("%d\n", getInt("two"));

    printf("\n%d\n", logicalOperation(" 1 > 3"));
    printf("%d\n", logicalOperation(" 2< 4 "));
    printf("%d\n", logicalOperation("1 ==3 "));

    readFromFile("input/main.fok");
    return 0;
}