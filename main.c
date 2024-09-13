#include <stdio.h>
#include "utils.h"
#include "numeric.h"

int main(int argc, const char** argv)
{
    // Idea: find a way to calculate any given tetration as efficiently as possible.
    //! You will need a novel method for this.
    printf("Welcome to the tetration calculator!\n");
    if (argc > 1) {
        printf("Args:\n");
        Numeric* num = make_large();
        for (int i = 1; i < argc; i++) {
            if (is_number(argv[i])) {
                int temp = atoi(argv[i]);
                printf("temp = %d\n", temp);
                push_large(&num, temp);
                for (size_t j = 0; j < num->value.large.size; j++) {
                    printf("Number: %d\n", num->value.large.digits[j]);
                }
            }
        }
        free_large(&num); // and here
    }
    return 0;
}
