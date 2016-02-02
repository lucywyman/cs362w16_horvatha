#include <stdio.h>
#include <stdlib.h>
#include "my_assert.h"

void my_assert(char* message){

    fprintf(stdout, "%s\n", message);

    exit(0);

}

