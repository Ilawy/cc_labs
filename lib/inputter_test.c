#include "inputter.h"
#include "stdio.h"


int main(){
    int result = prompt_int("Age: ");
    printf("%d\n", result);
    return 0;
}