#pragma once
#include <libsinterp/variables.h>

void makeVariable(char* name, int baseValue);
struct VarInt getVariable(char* name);
void setVariable(char* name, int newValue);