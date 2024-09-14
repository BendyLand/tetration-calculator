#include "utils.h"

bool check_input_parameters(int a, int b)
{
    bool result = true;
    if (a <= 2) {
        if (b >= 5) {
            result = false;
        }
    }
    else if (a >= 3 && a <= 9) {
        if (b >= 4) {
            result = false;
        }
    }
    else {
        if (b >= 3) {
            result = false;
        }
    }
    return result;
}

bool is_number(const char* arg)
{
    for (size_t i = 0; i < strlen(arg); i++) {
        if (!isdigit(arg[i])) return false;
    }
    return true;
}

