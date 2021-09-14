#include "minesweeper_lib/library.h"
#include <stddef.h>


char *hello(void) {
    return "Hello, World!";
}

bool IsDimensionValid(int rows, int columns){
    printf("In val func");
    bool validDims = rows > 0 && rows <= 100 && columns > 0 && columns <= 100;
    return validDims;
}

Field *CreateField(int rows, int columns) {
    Field *fieldPtr = NULL;
    if (!IsDimensionValid(rows, columns)){
        
        return fieldPtr;
    }    

    fieldPtr = malloc(sizeof(Field));
    fieldPtr->rows = rows;
    fieldPtr->columns = columns;

    fieldPtr->fieldArray = malloc(rows * sizeof(char*));
    for(int row=0; row<rows;row++){
        printf("Iter %i\n",row);
        fieldPtr->fieldArray[row] = malloc(columns * sizeof(char));
    }
    return fieldPtr;
}