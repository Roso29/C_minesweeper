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
    int rowLength = fieldPtr->columns;
    //printf("Row: %s\n",rowStr);
    char * rowAddr = fieldPtr->fieldArray[rowIndex];
    //printf("Pointer: %p\n", rowAddr);
    strncpy(rowAddr, rowStr, rowLength);
    //printf("Row in array: %s\n",fieldPtr->fieldArray[0]);
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