#include <stdio.h>
#include "function.h"
static int counter=0;

static void function(){

++counter;
printf("%d \n", counter);
}