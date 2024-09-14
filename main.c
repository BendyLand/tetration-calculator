#include "utils.h"
#include "numeric.h"

int main(int argc, const char** argv)
{
    // Idea: find a way to calculate any given tetration as efficiently as possible.
    //! You will need a novel method for this.
    if (argc > 1) {
        int args[2] = {0, 0};
        for (int i = 1; i < argc; i++) {
            if (is_number(argv[i])) {
                int temp = atoi(argv[i]);
                args[i-1] = temp;
            }
        }
        if (check_input_parameters(args[0], args[1])) {
            printf("Good to go!\n");
        }
        else {
            printf("The result of this operation is immense and will take a very long time to calculate.\nWould you like to proceed? (y/n)\n");
        }
    }
    return 0;
}
