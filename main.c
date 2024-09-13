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
        for (int i = 1; i < argc; i++) {
            if (is_number(argv[i])) {
                printf("%s\n", argv[i]);
            }
        }
    }
    return 0;
}
