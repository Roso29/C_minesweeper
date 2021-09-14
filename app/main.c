#include <stdio.h>
#include "minesweeper_lib/library.h"
#include <string.h>
#include <stdlib.h>

/**
 * The main entry point to the application.
 *
 * @return  0 on success, otherwise an error code.
 */

Field* GenerateField(int rows, int cols){
    char rowStr[cols];
    printf("IN gen field\n");
    Field* fieldPtr = CreateField(rows,cols);
    
    for(int rowI = 0; rowI < rows; rowI++){
        printf("I");
        scanf("%s",rowStr);
        printf("Row: %s\n",rowStr);
        AddRowToField(fieldPtr, rowI, rowStr);
        printf("J");
    }
    printf("IN gen field");
    return fieldPtr;
}

int main(void) {

    printf("Enter dimensions of field.\nThen enter each row.\n");
    
    bool nextInput = true;
    int rows;
    int cols;
    char* delim = " ";
    char dims[30];
    while (nextInput){
        printf("awaiting input");
        fgets(dims, sizeof(dims),stdin);
        
        rows = atoi(strtok(dims, delim));
        cols = atoi(strtok(NULL, delim)); 
        nextInput =(rows+cols != 0);
        if(nextInput){
            GenerateField(rows, cols);
        }
    }

    return 0;
}