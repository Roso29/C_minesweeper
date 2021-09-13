#include "minesweeper_lib/library.h"

char *hello(void) {
    return "Hello, World!";
}

Field *CreateField(int rows, int columns, char symbol) {
    Field *fieldPtr = NULL;
    if (columns > 100){
        return fieldPtr;
    }    
    fieldPtr = malloc(sizeof(Field));

    fieldPtr->rows = rows;
    fieldPtr->columns = columns;
    fieldPtr->symbol = '-';
    return fieldPtr;
}