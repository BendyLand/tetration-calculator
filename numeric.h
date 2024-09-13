#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum 
{
    SMALL, 
    MEDIUM, 
    LARGE,
    VERY_LARGE,
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
        struct {
            size_t size;
            long long* digits;
        } very_large;
    } value;
} Numeric;

void* malloc_or_exit(size_t size);
void* calloc_or_exit(size_t num, size_t size);
Numeric* make_small(int val);
size_t free_small(Numeric* num);
Numeric* make_medium(long long val);
size_t free_medium(Numeric* num);
Numeric* make_large();
size_t push_large(Numeric** num, int val);
int pop_large(Numeric** num);
size_t free_large(Numeric** num);
Numeric* make_very_large();
size_t push_very_large(Numeric** num, long long val);
long long pop_very_large(Numeric** num);
size_t free_very_large(Numeric** num);
