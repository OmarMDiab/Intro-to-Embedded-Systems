#include <stdio.h>
#include "types.h"

int y = 5;

int main(){
    int a =5;
    int b = 3;

    int result_macro = ADD_MACRO(x, y);
    printf("Using macro: %d + %d = %d\n", x, y, result_macro);

    int result_function = add_function(x, y);
    printf("Using function: %d + %d = %d\n", x, y, result_function);

    return 0;
}
