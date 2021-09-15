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
    int success=1;
    
    Field* fieldPtr = CreateField(rows,cols);
    
    for(int rowIndex = 0; rowIndex < rows; ++rowIndex){
        printf("Enter Row:");
        scanf("%s",rowStr);
        success = AddRowToField(fieldPtr, rowIndex, rowStr);   
    }
    
    return fieldPtr;
}

void OutputHintsForFields(Field** fields, int fieldCounter){
    for(int fieldsIndex=0; fieldsIndex < fieldCounter; fieldsIndex++){
        printf("Field #%d\n",fieldsIndex+1);
        CalculateFieldHints(fields[fieldsIndex]);
        PrintHints(fields[fieldsIndex]);
        printf("\n");
    }
}

int main(void) {

    printf("Enter dimensions of field.\nThen enter each row.\n");
    bool nextInput = true;
    int rows;
    int cols;
    int fieldCounter = 0;

    Field* fieldPtr;
    Field** fields = malloc(10 * sizeof(Field*));


    while (nextInput){
        
        scanf("%d %d", &rows, &cols);
        nextInput =(rows+cols != 0);
        
        if(nextInput){
            fieldPtr = GenerateField(rows, cols);
            printf("Adding field to fields at index %d\n",fieldCounter);
            fields[fieldCounter++] = fieldPtr;
        }
    }

    OutputHintsForFields(fields, fieldCounter);

    return 0;
}