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

void* malloc_or_exit(size_t size);
void* calloc_or_exit(size_t num, size_t size);
Numeric* make_small(int val);
size_t free_small(Numeric* num);
Numeric* make_medium(long long val);
size_t free_medium(Numeric* num);
Numeric* alloc_large(size_t size);
size_t free_large(Numeric** num);
