char *charToVar(char *line);
void trimSpaces(char **text);
int isInteger(char *text);
int isDouble(char *text);
void getArguments(char *text, int countSeparators, char (*separators)[countSeparators], char (*v1)[], char (*op)[], char (*v2)[]);