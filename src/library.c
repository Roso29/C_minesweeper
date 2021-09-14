#include "minesweeper_lib/library.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *hello(void) {
    return "Hello, World!";
}

bool IsDimensionValid(int rows, int columns){
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
        fieldPtr->fieldArray[row] = malloc(columns * sizeof(char));
    }
    return fieldPtr;
}

int AddRowToField(Field* fieldPtr, int rowIndex, char* rowStr){
    int rowLength = strlen(rowStr);
    if (rowLength!=fieldPtr->columns){
        return 0;
    }
    if (rowIndex >= fieldPtr->rows){
        return 0;
    }
    char * rowAddr = fieldPtr->fieldArray[rowIndex];
    strncpy(rowAddr, rowStr, rowLength);
    
    return 1;
}  

void PrintField(Field* fieldPtr){
    int rows = fieldPtr->rows;
    int columns = fieldPtr->columns;
    char** fieldArray = fieldPtr->fieldArray;

    for(int row=0;row < rows; row++){
        printf("%s\n",fieldArray[row]);
    }

}