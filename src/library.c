#include "minesweeper_lib/library.h"
#include <stddef.h>


char *hello(void) {
    return "Hello, World!";
}

bool IsDimensionValid(int rows, int columns){
    bool validDims = rows > 0 && rows <= 100 && columns > 0 && columns <= 100;
    return validDims;
}

Field *CreateField(int rows, int columns, char symbol) {
    Field *fieldPtr = NULL;
    if (IsDimensionValid(rows, columns)){
        return fieldPtr;
    }    

    fieldPtr = malloc(sizeof(Field));
    fieldPtr->rows = rows;
    fieldPtr->columns = columns;
    fieldPtr->symbol = '-';
    return fieldPtr;
}