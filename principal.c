#include <stdio.h>
#include <stdlib.h>

#include "funciones.c"

int menu();

int main(int argc, char const *argv[])
{
    int op;
    
    do
    {
        op = menu();
    } while (op!=5);
    
    return 0;
}
