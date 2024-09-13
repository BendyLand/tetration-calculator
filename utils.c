#include "utils.h"
#include <ctype.h>

bool is_number(const char* arg)
{
    for (size_t i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i])) return false;
    }
    return true;
}

