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

int FreeFieldResources(Field** fields, int fieldCounter){
    //free the resources of all the fields
    //For each fieldPtr in fields
        //First free the memory of each row in the fieldPtr->fieldArray and fieldPtr->fieldArray
        //Then free the memory of the fieldArray and fieldPtr
        //Then free the memory of the fieldPtr
    //Finally free the memory of the fields double pointer
    Field* fieldPtr;
    for(int fieldIndex=0; fieldIndex < fieldCounter; fieldIndex++){
        fieldPtr = fields[fieldIndex];
        for(int rowIndex = 0; rowIndex < fieldPtr->rows; rowIndex++){
            free(fieldPtr->fieldArray[rowIndex]);
            free(fieldPtr->hintArray[rowIndex]);
        }
        free(fieldPtr->fieldArray);
        free(fieldPtr->hintArray);
        free(fieldPtr);
    }
    free(fields);


}

int main(void) {

    printf("Enter dimensions of field.\nThen enter each row.\n");
    bool nextInput = true;
    int rows;
    int cols;
    int fieldCounter = 0;

    Field* fieldPtr;
    Field** fields = (Field**) malloc(10 * sizeof(Field*));


    while (nextInput){
        scanf("%d %d", &rows, &cols);
        nextInput =(rows+cols != 0);
        if(nextInput){
            fieldPtr = GenerateField(rows, cols);
            fields[fieldCounter++] = fieldPtr;
        }
        if(fieldCounter % 10 == 0){
            fields = (Field**) realloc(fields, fieldCounter+10);
        }
        
    }

    printf("\n\n");

    OutputHintsForFields(fields, fieldCounter);

    FreeFieldResources(fields, fieldCounter);

    return 0;
}