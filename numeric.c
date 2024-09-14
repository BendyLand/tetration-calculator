#include "numeric.h"

void* malloc_or_exit(size_t size)
{
    void* result = malloc(size);
    if (!result) {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* calloc_or_exit(size_t num, size_t size)
{
    void* result = calloc(num, size);
    if (!result) {
        fprintf(stderr, "Error allocating memory.\n");
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

//todo: Make capacity field to handle dynamic resizing more efficiently
size_t push_large(Numeric** num, int val)
{
    int* temp;
    if (large_digits(num)) {
        temp = (int*)realloc(large_digits(num), (large_size(num) + 1) * sizeof(int));
    }
    else {
        temp = (int*)malloc(sizeof(int)); 
    }
    if (!temp) {
        fprintf(stderr, "Unable to reallocate memory for large number 1.\n");
        return 1;
    }
    (*num)->value.large.size++;
    (*num)->value.large.digits = temp;
    (*num)->value.large.digits[large_size(num)-1] = val;
    return 0;
}

//todo: Make capacity field to handle dynamic resizing more efficiently
int pop_large(Numeric** num)
{
    if (large_size(num) == 0) {
        fprintf(stderr, "No elements in large number.\n");
        return -1;
    }
    int result = large_digit(num, large_size(num)-1);
    (*num)->value.large.size--;
    if (large_size(num) > 0) {
        int* temp = (int*)realloc(large_digits(num), (large_size(num) + 1) * sizeof(int));
        if (!temp) {
            fprintf(stderr, "Unable to reallocate memory for large number 2.\n");
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
        if (large_digits(num)) {
            free(large_digits(num));
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

//todo: Make capacity field to handle dynamic resizing more efficiently
size_t push_very_large(Numeric** num, long long val)
{
    long long* temp = NULL;
    if (v_large_digits(num)) {
        temp = (long long*)realloc(v_large_digits(num), (v_large_size(num) + 1) * sizeof(long long));
    }
    else {
        temp = (long long*)malloc(v_large_size(num) * sizeof(long long));
    }
    if (!temp) {
        fprintf(stderr, "Unable to reallocate memory for very large number.\n");
        return 1;
    }
    (*num)->value.very_large.size++;
    (*num)->value.very_large.digits = temp;
    (*num)->value.very_large.digits[v_large_size(num)-1] = val;
    return 0;
}

//todo: Make capacity field to handle dynamic resizing more efficiently
long long pop_very_large(Numeric** num)
{
    if (v_large_size(num) == 0) {
        fprintf(stderr, "No elements in very large number.\n");
        return -1;
    }
    long long result = v_large_digit(num, v_large_size(num)-1);
    (*num)->value.very_large.size--;
    if (v_large_size(num) > 0) {
        long long* temp = (long long*)realloc(v_large_digits(num), v_large_size(num) * sizeof(long long));
        if (!temp) {
            fprintf(stderr, "Unable to reallocate memory for very large number.\n");
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
        if (v_large_digits(num)) {
            free(v_large_digits(num));
            (*num)->value.very_large.digits = NULL;
        }
        free(*num);
        *num = NULL;
        return 0;
    }
    return 1;
}
