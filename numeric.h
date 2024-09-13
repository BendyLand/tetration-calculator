#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    SMALL, 
    MEDIUM, 
    LARGE,
} NumType;

typedef struct 
{
    NumType type;
    union {
        int small;
        long long medium;
        struct {
            size_t size;
            int* digits;
        } large;
    } value;
} Numeric;
