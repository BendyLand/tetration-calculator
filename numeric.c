#include "numeric.h"
#include <stdlib.h>

void* malloc_or_exit(size_t size)
{
    void* result = malloc(size);
    if (!result) {
        perror("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* calloc_or_exit(size_t num, size_t size)
{
    void* result = calloc(num, size);
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

Numeric* make_large()
{
    Numeric* result = (Numeric*)malloc_or_exit(sizeof(Numeric));
    result->type = LARGE;
    result->value.large.size = 0;
    result->value.large.digits = NULL;
    return result;
}

size_t push_large(Numeric** num, int val)
{
    int* temp = NULL;
    if ((*num)->value.large.digits) {
        temp = (int*)realloc((*num)->value.large.digits, ((*num)->value.large.size + 1) * sizeof(int));
    }
    if (!temp) {
        perror("Unable to reallocate memory for large number.\n");
        return 1;
    }
    (*num)->value.large.size++;
    (*num)->value.large.digits = temp;
    (*num)->value.large.digits[(*num)->value.large.size-1] = val;
    return 0;
}

int pop_large(Numeric** num)
{
    if ((*num)->value.large.size == 0) {
        perror("No elements in large number.\n");
        return -1;
    }
    int result = (*num)->value.large.digits[(*num)->value.large.size-1];
    (*num)->value.large.size--;
    if ((*num)->value.large.size > 0) {
        int* temp = (int*)realloc((*num)->value.large.digits, ((*num)->value.large.size) * sizeof(int));
        if (!temp) {
            perror("Unable to reallocate memory for large number.\n");
            return -1;
        }
        (*num)->value.large.digits = temp;
    }
    else {
        printf("Cannot reallocate large number any smaller.\n");
    }
    return result;
}

size_t free_large(Numeric** num)
{
    if (num && *num) {
        if ((*num)->value.large.digits) {
            free((*num)->value.large.digits); // here
            (*num)->value.large.digits = NULL;
        }
        free(*num);
        *num = NULL;
        return 0;
    }
    return 1;
}

Numeric* make_very_large()
{
    Numeric* result = (Numeric*)malloc_or_exit(sizeof(Numeric));
    result->type = VERY_LARGE;
    result->value.very_large.size = 0;
    result->value.very_large.digits = NULL;
    return result;
}

size_t push_very_large(Numeric** num, long long val)
{
    long long* temp = NULL;
    if ((*num)->value.very_large.digits) {
        temp = (long long*)realloc((*num)->value.very_large.digits, ((*num)->value.very_large.size + 1) * sizeof(long long));
    }
    if (!temp) {
        perror("Unable to reallocate memory for very large number.\n");
        return 1;
    }
    (*num)->value.very_large.size++;
    (*num)->value.very_large.digits = temp;
    (*num)->value.very_large.digits[(*num)->value.very_large.size-1] = val;
    return 0;
}

long long pop_very_large(Numeric** num)
{
    if ((*num)->value.very_large.size == 0) {
        perror("No elements in very large number.\n");
        return -1;
    }
    long long result = (*num)->value.very_large.digits[(*num)->value.very_large.size-1];
    (*num)->value.very_large.size--;
    if ((*num)->value.very_large.size > 0) {
        long long* temp = (long long*)realloc((*num)->value.very_large.digits, ((*num)->value.very_large.size) * sizeof(long long));
        if (!temp) {
            perror("Unable to reallocate memory for very large number.\n");
            return -1;
        }
        (*num)->value.very_large.digits = temp;
    }
    else {
        printf("Cannot reallocate very large number any lower.\n");
    }
    return result;
}

size_t free_very_large(Numeric** num)
{
    if (num && *num) {
        if ((*num)->value.very_large.digits) {
            free((*num)->value.very_large.digits);
            (*num)->value.very_large.digits = NULL;
        }
        free(*num);
        *num = NULL;
        return 0;
    }
    return 1;
}
