#include <libsinterp/variables.h>
#include <libsinterp/executor.h>
#include <libsinterp/operators.h>
#include <libsinterp/strlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *fileText = readFromFile("input/main.fok");
    execute(fileText);

    return 0;
}