#include <libsinterp/variables.h>
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
    return 0;
}