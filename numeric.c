#include "numeric.h"

void* malloc_or_exit(size_t size)
{
    void* result = malloc(sizeof(size));
    if (!result) {
        perror("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* calloc_or_exit(size_t num, size_t size)
{
    void* result = calloc(num, sizeof(size));
    if (!result) {
        perror("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

Numeric* make_small(int val)
{
    Numeric* result = (Numeric*)malloc_or_exit(sizeof(Numeric));
    result->type = SMALL;
    result->value.small = val;
    return result;
}

size_t free_small(Numeric* num)
{
    if (num) {
        free(num);
        num = NULL;
        return 0;
    }
    return 1;
}

Numeric* make_medium(long long val)
{
    Numeric* result = (Numeric*)malloc_or_exit(sizeof(Numeric));
    result->type = MEDIUM;
    result->value.medium = val;
    return result;
}

size_t free_medium(Numeric* num)
{
    if (num) {
        free(num);
        num = NULL;
        return 0;
    }
    return 1;
}

Numeric* alloc_large(size_t size)
{
    Numeric* result = (Numeric*)malloc_or_exit(sizeof(Numeric));
    result->type = LARGE;
    result->value.large.size = size;
    result->value.large.digits = (int*)malloc_or_exit(size * sizeof(int));
    return result;
}

size_t free_large(Numeric** num)
{
    if (num && *num) {
        if ((*num)->value.large.digits) {
            free((*num)->value.large.digits);
            (*num)->value.large.digits = NULL;
        }
        free(*num);
        *num = NULL;
        return 0;
    }
    return 1;
}
